#include <stdio.h>
#include <algorithm>
int x[100010],y[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) y[i]=x[i];
	for(int i=1;i<=b%1024;i++)
	{
		int j;
		for(j=1;j<=a;j++) if(j%2==1) y[j]^=c;
		std::sort(y+1,y+a+1);
	}
	printf("%d %d",y[a],y[1]);
}