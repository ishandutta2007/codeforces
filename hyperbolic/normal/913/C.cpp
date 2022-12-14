#include <stdio.h>

long long int MAX = 1;
int a,x[50];
long long int func(int k)
{
	if(k==0) return 0;
	int pivot = a+1;
	for(int i=1;i<=a;i++)
	{
		int c = (1<<(i-1));
		if(c>=k)
		{
			pivot = i;
			break;
		}
	}
	
	long long int minCost = MAX;
	int index = 0;
	for(int i=1;i<pivot;i++)
	{
		minCost*=2;
		if(x[i]<minCost)
		{
			minCost = x[i];
			index = i;
		}
	}
	
	long long int s1,s2;
	if(index==0) s1 = MAX;
	else
	{
		int capacity = (1<<(index-1));
		int count = k/capacity;
		s1 = (long long int)x[index]*count+func(k-count*capacity);
	}
	
	minCost = MAX;
	index = 0;
	for(int i=pivot;i<=a;i++)
	{
		if(x[i]<minCost)
		{
			minCost = x[i];
			index = i;
		}
	}
	if(index==0) s2 = MAX;
	else s2 = minCost;
	
	return s1<s2?s1:s2;
}
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	MAX++;
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	printf("%I64d",func(b));
}