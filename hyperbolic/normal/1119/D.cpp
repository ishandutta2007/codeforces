#include <stdio.h>
#include <algorithm>

long long int x[100010],y[100010],S[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<a;i++) y[i] = x[i+1] - x[i];
	std::sort(y+1,y+a);
	for(int i=1;i<a;i++) S[i] = S[i-1] + y[i];
	
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		long long int e = d-c+1;
		
		int ans = 0;
		int min = 1, max = a-1;
		while(min<=max)
		{
			int h = (min+max)/2;
			
			if(y[h]>=e) max = h-1;
			else
			{
				min = h+1;
				ans = h;
			}
		}
		printf("%lld ",S[ans] + (a-ans)*e);
	}
}