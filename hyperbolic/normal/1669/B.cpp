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
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a-2;i++)
		{
			if(x[i]==x[i+1]&&x[i+1]==x[i+2])
			{
				printf("%d\n",x[i]);
				goto u;
			}
		}
		printf("-1\n");
		u:;
	}
}