#include<stdio.h>
#include<math.h>
#include<string.h>
void swap(int *a,int *b)
    {
int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
int n,w,sum=0,flag=0;
scanf("%d%d",&n,&w);
int a_1[n],index[n],w_1[n];
for(int i=0;i<n;i++)
    scanf("%d",&a_1[i]);
    for(int i=0;i<n;i++)
        index[i]=i;
    for(int i=0;i<n-1;i++)
        {
    for(int j=0;j<n-i-1;j++)
        {
        if(a_1[j]>a_1[j+1])
            {
            swap(&a_1[j],&a_1[j+1]);
            swap(&index[j],&index[j+1]);
        }
    }
    }
for(int i=0;i<n;i++)
    w_1[i]=(a_1[i]+1)/2;
    //for(int i=0;i<n;i++)
        //printf("%d ",w_1[i]);
    sum=w_1[0];
for(int i=1;i<n;i++)
    {
    if(w_1[i]<w_1[i-1]&&a_1[i]>a_1[i-1])
        w_1[i]=w_1[i-1]+1;
    else if(w_1[i]<w_1[i-1]&&a_1[i]==a_1[i-1])
        w_1[i]=w_1[i-1];
    sum+=w_1[i];
}
    //printf("%d %d",sum,w);
    if(sum>w)
        flag=1;
    else if(sum<=w)
        {
        int counter=w-sum,i=n-1;
        while(counter!=0)
            {
            if(a_1[i]-w_1[i]>counter)
                {
                w_1[i]+=counter;
                counter=0;
            }
            else
                {
                counter-=(a_1[i]-w_1[i]);
                w_1[i]=a_1[i];
            }
            i--;
        }
    }
    for(int i=0;i<n-1;i++)
        {
    for(int j=0;j<n-i-1;j++)
        {
        if(index[j]>index[j+1])
            {
            swap(&w_1[j],&w_1[j+1]);
            swap(&index[j],&index[j+1]);
        }
    }
    }
    if(flag==1)
        printf("-1");
    else
        {
    for(int i=0;i<n;i++)
        printf("%d ",w_1[i]);
    }
}