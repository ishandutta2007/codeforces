#include <stdio.h>

int ans[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) ans[i] = 0;
		
		for(int i=1;i<=a-3;i++) ans[i] = i-1;
		int val = 0;
		for(int i=1;i<=a-3;i++) val ^= ans[i];
		ans[a-2] = val+(1<<20);
		ans[a-1] = 3*(1<<20);
		ans[a] = 2*(1<<20);
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}