#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		if(sum==b) printf("YES\n");
		else printf("NO\n");
	}
}