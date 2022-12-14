#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=a-1;i>=1;i-=2)
		{
			if(x[i]>x[i+1])
			{
				int t = x[i];
				x[i] = x[i+1];
				x[i+1] = t;
			}
		}
		for(int i=1;i<a;i++)
		{
			if(x[i]>x[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}