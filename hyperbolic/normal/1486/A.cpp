#include <stdio.h>
#include <algorithm>

long long int x[110];
int main()
{
	x[0] = -1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=2;i<=a;i++) if(x[i-1]>=x[i-2]+1) x[i] += (x[i-1]-(x[i-2]+1)), x[i-1] = x[i-2]+1;
		for(int i=1;i<a;i++)
		{
			if(x[i]>=x[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}