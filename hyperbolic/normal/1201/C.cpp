#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	long long int min = 1, max = 2000000001;
	int ans = 0;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int sum = 0;
		for(int i=(a+1)/2;i<=a;i++) if(x[i]<h) sum += (h-x[i]);
		
		if(b>=sum)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	printf("%d",ans);
}