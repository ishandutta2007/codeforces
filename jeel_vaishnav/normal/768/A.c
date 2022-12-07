#include<stdio.h>
int main()
{
	int n,min=1000000001,max=-1,min_count=0,max_count;
	scanf("%d",&n);
	int a;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>max)
		{
			max=a;
			max_count=1;
		}
		else if(a==max)
		{
			max_count++;
		}
		if(a<min)
		{
			min=a;
			min_count=1;
		}
		else if(a==min)
		{
			min_count++;
		}
	}
	int ans=0;
	if(max==min)
	ans=0;
	else
	{
		ans=n-max_count-min_count;
	}
	printf("%d",ans);
}