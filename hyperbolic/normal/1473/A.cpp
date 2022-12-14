#include <stdio.h>
#include <algorithm>

int x[200010];
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
		if(x[1]+x[2]<=b) printf("YES\n");
		else
		{
			for(int i=1;i<=a;i++)
			{
				if(x[i]>b)
				{
					printf("NO\n");
					goto u;
				}
			}
			printf("YES\n");
			u:;
		}
	}
}