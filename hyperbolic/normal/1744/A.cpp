#include <stdio.h>

int x[110];
char y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		scanf("%s",y+1);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				if(x[i]==x[j]&&y[i]!=y[j])
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		printf("YES\n");
		u:;
	}
}