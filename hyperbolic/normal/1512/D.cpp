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
		a+=2;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		long long int sum = 0;
		for(int i=1;i<=a-1;i++) sum += x[i];
		long long int t = sum - x[a];
		for(int i=1;i<=a-1;i++)
		{
			if(x[i]==t)
			{
				for(int j=1;j<=a-1;j++)
				{
					if(j==i) continue;
					printf("%d ",x[j]);
				}
				printf("\n");
				goto u;
			}
		}
		
		sum = 0;
		for(int i=1;i<=a-2;i++) sum += x[i];
		if(sum==x[a-1])
		{
			for(int i=1;i<=a-2;i++) printf("%d ",x[i]);
			printf("\n");
		}
		else printf("-1\n");
		
		
		u:;
	}
}