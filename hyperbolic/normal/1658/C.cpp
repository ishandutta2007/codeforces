#include <stdio.h>

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
		for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
		
		int start = -1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==1)
			{
				if(start==-1) start = i;
				else
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		
		for(int i=start+1;i<=start+a;i++)
		{
			if(x[i]>x[i-1]+1)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		
		u:;
	}
}