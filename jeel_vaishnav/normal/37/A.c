#include<stdio.h>
void merge(int arr_1[],int arr_2[],int size,int arr_3[])
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
void merge_sort(int a[],int start,int end,int a_1[])
    {
    int size=end-start+1;
    if(start==end)
        a_1[0]=a[start];
    else
        {
        int mid=(start+end)/2;
        int arr_1[mid-start+1],arr_2[end-mid];
        merge_sort(a,start,mid,arr_1);
        merge_sort(a,mid+1,end,arr_2);
        merge(arr_1,arr_2,size,a_1);
    }
}
int main()
{
int n;
scanf("%d",&n);
int height[n],height_1[n];
for(int i=0;i<n;i++)
scanf("%d",&height[i]);
merge_sort(height,0,n-1,height_1);
int i=0,count=1,ans=0,max=0;
while(i<n)
{
count=1;
i++;
	while(height_1[i]==height_1[i-1]&&i<n)
	{
	i++;
	count++;
	}
if(count>max)
max=count;
ans++;
}
printf("%d %d",max,ans);
}