#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	scanf("%d",&b[i]);
	int count=0,ele[2],k=0,freq[n];
	for(int i=0;i<n;i++)
	freq[i]=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			count++;
			ele[k++]=i;
		}
		else
		freq[a[i]-1]++;
	}
	if(count==1)
	{
		for(int i=0;i<n;i++)
		{
			if(freq[i]==0)
			a[ele[0]]=i+1;
		}
	}
	else
	{
		if(freq[b[ele[0]]-1]==0&&freq[a[ele[1]]-1]==0)
		a[ele[0]]=b[ele[0]];
		else
		a[ele[1]]=b[ele[1]];
	}
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}