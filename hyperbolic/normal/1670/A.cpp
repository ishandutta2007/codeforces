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
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]<0) x[i]*=-1, count++;
		}
		for(int i=1;i<=count;i++) x[i]*=-1;
		
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