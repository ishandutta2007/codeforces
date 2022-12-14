#include <stdio.h>
#include <algorithm>

int x[1010],y[1010];
int main()
{
	int a;
	long long b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 0;
	int min = 1, max = a;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i = 1 ;i<=h;i++) y[i] = x[i];
		std::sort(y+1,y+h+1);
		
		long long int sum = 0;
		for(int i=h;i>=1;i-=2) sum += y[i];
		if(sum>b) max = h-1;
		else
		{
			ans = h;
			min = h+1;
		}
	}
	printf("%d",ans);
}