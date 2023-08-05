#include <stdio.h>
#include <stdlib.h>
int count=0;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
struct Node *temp = NULL;
void add(int m,int p)
{
    count+=1;
    struct Node *emp;
    emp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        emp->data = m;
        emp->next = NULL;
        head = emp;
        temp = emp;
    }
    else
    {
        if(p==1)
        {
            emp->data = m;
            emp->next = head;
            head = emp;
        }
        else if (p==count)
        {
            emp->data = m;
            emp->next = NULL;
            temp->next = emp;
            temp = emp;
        }
        else
        {
        int s=1;
        struct Node *ptr;
        ptr = head;
        while (s!=p-1)
        {
        ptr = ptr->next;
        s++;
        }
        emp->next=ptr->next;
        ptr->next=emp;
        emp->data=m;
        }
    }
}
int delete(int p)
{
    struct Node *emp;
    emp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        
        if(p==1)
        {
            emp=head->next;
            free(head);
            head=emp;
        }
        else
        {
        int s=1;
        struct Node *ptr;
        ptr = head;
        while (s!=p-1)
        {
        ptr = ptr->next;
        s++;
        }
        emp=ptr->next;
        if(p==count)
        {
        ptr->next=NULL;
        free(emp);
        }
        else
        {
            emp=emp->next;
            ptr->next=emp;
        }
        }
        count-=1;
    }
    return 1;
}
void display(struct Node *head)
{
    struct Node *p;
    p = head;
    while (p != NULL)
    {
        printf("\n%d", p->data);
        p = p->next;
    }
}
void main()
{
    int ch;
    int num,pos,s=1;
    while(s)
    {
    printf("\nEnter 1 to add, 2 to delete and 3 to print (No. of nodes present: %d)\n",count);
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\nEnter the no. ");
        scanf("%d",&num);
        printf("\nEnter position ");
        scanf("%d",&pos);
        if(pos>count+1 || pos<1)
        {
            printf("Invalid");
        }
        add(num,pos);
        break;
        case 2:
        printf("\nEnter position to delete ");
        scanf("%d",&pos);
        if(pos>count+1 || pos<1)
        {
            printf("Invalid");
        }
        else if (delete(pos)==0)
        {
            printf("Already Empty");
        }
        break;
        case 3:
        display(head);
        default:
        s=0;    
    }
    }

}