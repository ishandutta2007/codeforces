#include<stdio.h>
#include<math.h>
#include<string.h>
void merge(int arr_1[],int arr_2[],int size,int arr_3[])
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
    int a[n],b[n],flag=0,check=0;
    for(int i=0;i<n;i++)
        {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]!=b[i])
            flag=1;
        if(i>0)
            {
            if(a[i-1]<a[i])
                check=1;
        }
    }
    if(flag==1)
        printf("rated");
    else if(check==0)
        printf("maybe");
        else
        printf("unrated");
    return 0;
}