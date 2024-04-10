#include <stdio.h>
int abs(int k)
{
	return k>0?k:-k;
}
int x[1010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int ans = 12345678;
	
	for(int i=1;i<=a;i++)
	{
		if(0<x[i]&&x[i]<=c)
		{
			ans = ans<abs(i-b)*10?ans:abs(i-b)*10;
		}
	}
	printf("%d",ans);
}