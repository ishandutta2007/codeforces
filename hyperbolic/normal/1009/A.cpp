#include <stdio.h>

int x[1010],y[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	int ans = 0;
	int p = 1;
	for(int i=1;i<=a;i++)
	{
		if(p<=b && x[i]<=y[p])
		{
			ans++;
			p++;
		}
	}
	printf("%d",ans);
}