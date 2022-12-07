#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void merge(long long int arr_1[],long long int arr_2[],int size,long long int arr_3[])
    {
    int i=0,j=0,k=0,size_i=(size+1)/2,size_j=size-size_i;
    while(k<size)
        {
        if((arr_1[i]<=arr_2[j]||i==size_i)&&j!=size_j)
            arr_3[k++]=arr_2[j++];
        else
            arr_3[k++]=arr_1[i++];
    }
}
void merge_sort(long long int a[],int start,int end,long long int a_1[])
    {
    int size=end-start+1;
    if(start==end)
        a_1[0]=a[start];
    else
        {
        int mid=(start+end)/2;
        long long int arr_1[mid-start+1],arr_2[end-mid];
        merge_sort(a,start,mid,arr_1);
        merge_sort(a,mid+1,end,arr_2);
        merge(arr_1,arr_2,size,a_1);
    }
}
int main()
{
   long long int n,f;
   scanf("%I64d%I64d",&n,&f);
   long long int k,l;
   long long int diff[n],diff_1[n],sum=0;
   for(int i=0;i<n;i++)
       {
       scanf("%I64d%I64d",&k,&l);
       diff[i]=l-k;
       if(k<diff[i])
       diff[i]=k;
       if(l>k)
       sum+=k;
       if(l<=k)
       sum+=l;
   }
   merge_sort(diff,0,n-1,diff_1);
   for(int i=0;i<f;i++)
       {
       if(diff_1[i]>0)
           sum+=diff_1[i];
   }
    printf("%I64d",sum);
}