#include <stdio.h>
#include <algorithm>

int x[110],y[110];
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
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+a+1);
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]>y[i])
			{
				printf("NO\n");
				goto u;
			}
			if(x[i]<y[i]-1)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}