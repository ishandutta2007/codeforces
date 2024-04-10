#include <stdio.h>
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int S = 0;
		for(int i=1;i<a;i++)
		{
			S += x[i];
			if(S<=0)
			{
				printf("NO\n");
				goto u;
			}
		}
		S = 0;
		for(int i=a;i>1;i--)
		{
			S += x[i];
			if(S<=0)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}