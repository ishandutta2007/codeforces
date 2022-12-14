#include <stdio.h>
#include <algorithm>

int sum[10];
int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sum[0] = sum[1] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		for(int i=1;i<=a;i++) sum[x[i]%2]++;
		if(sum[0]%2==0)
		{
			printf("YES\n");
			continue;
		}
		else
		{
			for(int i=1;i<a;i++)
			{
				if(x[i+1]-x[i]==1)
				{
					printf("YES\n");
					goto u;
				}
			}
		}
		printf("NO\n");
		u:;
	}
}