#include <stdio.h>

int x[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		printf("%lld\n",(long long int)(x[e]-x[d]+1 - (e-d+1))*2 + (x[d]-1)+(c-x[e]));
	}
}