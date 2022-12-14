#include <stdio.h>

int x[100010],y[100010],check1[100010],check2[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++) check1[i] = check2[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==1)
			{
				for(int j=i+1;j<=a;j++) check1[j] = 1;
				break;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(x[i]==-1)
			{
				for(int j=i+1;j<=a;j++) check2[j] = 1;
				break;
			}
		}
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]<y[i])
			{
				if(check1[i]==0)
				{
					printf("NO\n");
					goto u;
				}
			}
			else if(x[i]>y[i])
			{
				if(check2[i]==0)
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