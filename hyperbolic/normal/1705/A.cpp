#include <stdio.h>
#include <algorithm>

int x[210];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+2*a+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i+a]<x[i]+b)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}