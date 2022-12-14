#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int s = 0;
		for(int i=1;i<=a;i++) s += x[i];
		printf("%d\n",s<b?s:b);
	}
}