#include <stdio.h>
#include <algorithm>

int x[110],sum[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		if(sum[a]==b)
		{
			printf("NO\n");
			continue;
		}
		
		for(int i=1;i<a;i++)
		{
			if(sum[i]==b)
			{
				int t = x[a];
				x[a] = x[i];
				x[i] = t;
				break;
			}
		}
		
		printf("YES\n");
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}