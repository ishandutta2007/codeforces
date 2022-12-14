#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(j*j==x[i])
				{
					goto u;
				}
			}
			printf("YES\n");
			goto v;
			u:;
		}
		printf("NO\n");
		v:;
	}
}