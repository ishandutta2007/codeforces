#include <stdio.h>
#include <algorithm>

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
		std::sort(x+1,x+a+1);
		for(int i=1;i<a;i++)
		{
			if(x[i+1]-x[i]>=2)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}