#include <stdio.h>
#include <algorithm>
int a,b,c,d;
int x[100010];

long long int func(long long int s, long long int t)
{
	int min = 1, max = b;
	int ans1 = b+1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(x[h]>=s)
		{
			ans1 = h;
			max = h-1;
		}
		else min = h+1;
	}
	
	min = 1, max = b;
	int ans2 = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(x[h]<=t)
		{
			ans2 = h;
			min = h+1;
		}
		else max = h-1;
	}
	if(ans1>ans2) return c;
	if(s==t) return (long long int)(ans2-ans1+1)*d;
	
	long long int h = (s+t)/2;
	long long int S1 = func(s,h) + func(h+1,t);
	long long int S2 = (long long int)(ans2-ans1+1)*d*(t-s+1);
	return S1<S2?S1:S2;
}

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+b+1);
	
	printf("%lld",func(1,(1<<a)));
}