#include <stdio.h>
#include <algorithm>

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = x[i];
		std::sort(y+1,y+a+1);
		
		for(int i=1;i<=a;i++)
		{
			if(i-b<1 && i+b>a)
			{
				if(x[i]!=y[i])
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