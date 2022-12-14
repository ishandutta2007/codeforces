#include <stdio.h>
int x[30010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int m = x[1];
		x[1] = 0;
		for(int i=2;i<=a;i++)
		{
			if(x[i]>=x[i-1])
			{
				m = m<(x[i]-x[i-1])?m:(x[i]-x[i-1]);
				x[i] -= m;
			}
		}
		for(int i=a-1;i>=1;i--)
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