#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int check=1000000000000000000;
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
    	if(end<start)
    	return;
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
long long int a[4000];
long long int x_1,y_1,l,r,dig_x,dig_y;
scanf("%I64d%I64d%I64d%I64d",&x_1,&y_1,&l,&r);
long long int x[63],y[63];
x[0]=1;
y[0]=1;
int i=0;
for(i=1;i<63;i++)
{
if(check/x_1<x[i-1])
{
break;
}
x[i]=x[i-1]*x_1;
}
dig_x=i;
for(i=1;i<63;i++)
{
if(check/y_1<y[i-1])
break;
y[i]=y[i-1]*y_1;
}
dig_y=i;
int k=0;
for(int i=0;i<dig_x;i++)
{
	for(int j=0;j<dig_y;j++)
	{
		if(r-y[j]>=x[i])
		{
		a[k++]=x[i]+y[j];
		//printf("%lld ",a[k-1]);
		}
	}
}
//printf("\n");
long long int a_1[k];
merge_sort(a,0,k-1,a_1);
//for(int i=0;i<k;i++)
//printf("%lld ",a_1[i]);
//printf("\n");
int j=0;
while(a_1[j]<l)
j++;
long long int ans=0,prev=l;
if(a_1[j]!=l)
prev=l-1;
while(a_1[j]<=r&&j<k)
{
	if(a_1[j]-prev-1>ans)
	ans=a_1[j]-prev-1;
	//printf("%lld %lld %lld\n",a_1[j],prev,ans);
	prev=a_1[j];
	j++;
}
if(r-prev>ans)
ans=r-prev;
printf("%I64d",ans);
}