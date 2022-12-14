#include <stdio.h>

int x[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int max = x[1];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		for(int i=1;i<=a;i++) x[i] |= b;
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		printf("%d\n",max);
	}
}