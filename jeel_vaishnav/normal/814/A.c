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
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n],b[k],b_1[k];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<k;i++)
	scanf("%d",&b_1[i]);
	merge_sort(b_1,0,k-1,b);
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0&&j<k)
		{
		a[i]=b[j];	
		j++;
		}
	}
	int check=0;
	//for(int i=0;i<n;i++)
	//printf("%d ",a[i]);
	//printf("\n");
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			check=1;
			break;
		}
	}
	if(check==1)
	printf("Yes");
	else
	printf("No");
}