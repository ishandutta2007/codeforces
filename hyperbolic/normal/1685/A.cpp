#include <stdio.h>
#include <algorithm>
int x[200010],y[200010];
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
		
		int p = 1;
		for(int i=1;i<=a;i+=2) y[i] = x[p++];
		for(int i=2;i<=a;i+=2) y[i] = x[p++];
		for(int i=a+1;i<=2*a;i++) y[i] = y[i-a];
		
		for(int i=2;i<=a;i++)
		{
			if(y[i-1]>y[i]&&y[i]<y[i+1]);
			else if(y[i-1]<y[i]&&y[i]>y[i+1]);
			else
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
		u:;
	}
}