#include <stdio.h>
#include <algorithm>

int x[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+b+1);
		x[b+1] = a;
		
		int ans = 1;
		int min = 2, max = b;
		while(min<=max)
		{
			int h = (min+max)/2;
			long long int sum = 0;
			for(int i=b-h+1;i<=b;i++)
			{
				long long int p = (long long int)(x[i+1]-x[i])*(i-(b-h+1)+1);
				sum += p;
				if(sum-1>=x[i+1]-1)
				{
					max = h-1;
					goto u;
				}
			}
			ans = h;
			min = h+1;
			u:;
		}
		printf("%d\n",ans);
	}
}