/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
int temp;
for (int i=sl.head ; st[i].next != -1 ; i=st[i].next)
{
if (compare(st[st[i].next].ele , j) == GREATER)
break;
}
temp = nextfreeloc++;
st[temp].next = st[i].next;
st[temp].ele = j;
st[i].next = temp;
sl.size++;
return sl;
}
  
void insertelements (JobList list , int size, SeqList s[3])
{

for(int j=0;j <3;j++){
s[j] = createlist();
for(int i=0;i<size;i++){
if(list[i].pri == j) insert(list[i], s[j]);
}
}


}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function

}

void printlist(SeqList sl)
{

// Implement this function
for (int i=st[sl.head].next ; st[i].next != -1 ; i=st[i].next)
 printjob (st[i].ele);
}

void printJobList(JobList list, int size)
{

// Implement this function
for (int i=0;i<size;i++)
  printjob (j[i]);

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
