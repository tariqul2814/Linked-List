#include <iostream>
using namespace std;
int rec=0;
struct node
{
    int value;
    node *next;
};
node *head=NULL;
void insertion_at_first(int n)
{
    node *temp;
    temp=head;
    node *newnode;
    newnode=new node;
    head=newnode;
    newnode->next=temp;
    newnode->value=n;
    rec++;
}

void deletation_at_last()
{
     node *temp,*dletenode;
     temp=head;
     for(int i=1;i<rec-1;i++)
     {
         temp=temp->next;
     }
     dletenode=temp->next;
     temp->next=NULL;
     rec--;
     delete dletenode;
}

void delete_any_position(int pos)
{
    node *temp,*temp1,*temp2;
    temp=head;
    temp1=temp;
    //temp2=temp1;
    for(int i=1;i<=rec;i++)
    {
        if(i==pos)
        {
            if(i!=1)
            {
                temp2=temp->next;
            delete temp;
            temp1->next=temp2;
            rec--;
            }
            if(i==1)
            {
                temp2=temp->next;
                delete temp;
                head=temp2;
                rec--;
            }
            break;
        }
        temp1=temp;
        if(i!=pos)
        {
            temp=temp->next;
        }
    }
}

void deletation_at_first()
{
    node *temp;
    temp=head;
    head=temp->next;
    delete temp;
    rec--;
}
void insertion_at_last(int n)
{
    node *temp;
    node *newnode;
    temp=head;
    newnode=new node;
    if(head==NULL)
    {
        head=newnode;
        newnode->value=n;
        newnode->next=NULL;
    }
    else
    {

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->value=n;
        newnode->next=NULL;
    }
    rec++;
}

int insertion_at_any_index(int n,int pos)
{
    node *temp,*newnode,*prevnode,*nexnode;
    temp=head;
    newnode = new node;
    if(pos==1)
    {
      newnode->next=temp;
      head=newnode;
      newnode->value=n;
    }
    else if(pos==rec+1)
    {
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        newnode->value=n;
    }
    else if(rec+1>pos)
    {
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        nexnode=temp->next;
        newnode->next=nexnode;
        newnode->value=n;
        temp->next=newnode;
    }
    else
        cout<<"Out Of Range At Any Index"<<endl;
    rec++;
}
void traverse()
{
    node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->value<<endl;
        temp=temp->next;
    }
    cout<<temp->value<<endl;

}
int main()
{
    insertion_at_last(50);
    insertion_at_last(10);
    insertion_at_last(20);
    insertion_at_first(1);
    deletation_at_last();
    insertion_at_any_index(5,4);
    deletation_at_first();
    delete_any_position(2);
    traverse();
}
