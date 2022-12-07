#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
long long int mod=1000000007;
void merge(long long int arr_1[],long long int arr_2[],int size,long long int arr_3[])
    {
    int i=0,j=0,k=0,size_i=(size+1)/2,size_j=size-size_i;
    while(k<size)
        {
        if((arr_1[i]>=arr_2[j]||i==size_i)&&j!=size_j)
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
   long long int n;
   scanf("%I64d",&n);
   long long int p2[n-1],value=1;
   p2[0]=1;
   for(int i=1;i<n-1;i++)
       {
    value=(value*2)%mod;
    p2[i]=(p2[i-1]+value)%mod;
   }
   long long int x[n],x_1[n],sum=0;
    for(int i=0;i<n;i++)
        scanf("%I64d",&x_1[i]);
    merge_sort(x_1,0,n-1,x);
    for(int i=1;i<n;i++)
        {
        sum=(sum+(x[i]*p2[i-1])%mod)%mod;
      
    }
    long long int sum_2=0;
    for(int i=n-2;i>=0;i--)
        {
        sum_2=(sum_2+(x[i]*p2[n-2-i])%mod)%mod;
        
    }
    printf("%I64d",((sum-sum_2)%mod+mod)%mod);
}