#include <stdio.h>

int x[1000010],y[1000010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++) scanf("%d",&x[i]);
	for(int i=0;i<b;i++) scanf("%d",&y[i]);
	
	int ans = 0;
	for(int i=0;i<a;i++)
	{
		if(x[i]%c!=0)
		{
			ans += i;
			break;
		}
	}
	for(int i=0;i<b;i++)
	{
		if(y[i]%c!=0)
		{
			ans += i;
			break;
		}
	}
	printf("%d",ans);
}