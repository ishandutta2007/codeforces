#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int temp[200001]={0},l,r;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        temp[l]++;
        if(r!=200000)
        temp[r+1]--;
    }
    temp[0]=0;
    for(int i=1;i<200001;i++)
    {
        temp[i]=temp[i-1]+temp[i];
    }
    for(int i=1;i<200001;i++)
    {
        if(temp[i]>=k)
            temp[i]=1;
        else
            temp[i]=0;
    }
    for(int i=1;i<200001;i++)
    {
        temp[i]=temp[i-1]+temp[i];
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",temp[r]-temp[l-1]);
    }
}