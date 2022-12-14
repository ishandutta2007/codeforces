#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%d%d%d",&x[1],&x[2],&x[3],&a);
		
		int p = 1;
		for(int i=2;i<=3;i++) if(x[p]<x[i]) p = i;
		
		int min = 0, max = x[1]+x[2]+x[3]-3;
		if(x[p]>=x[1]+x[2]+x[3]-x[p]+1) min = x[p] - (x[1]+x[2]+x[3]-x[p]+1);
		
		if(min<=a&&a<=max) printf("YES\n");
		else printf("NO\n");
	}
}