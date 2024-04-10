#include <stdio.h>
#define MAX 1e9

long long int ans[110];
int main()
{
	ans[1] = 1;
	for(int i=2;i<=30;i++) ans[i] = 3*ans[i-1];
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a>=20) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
			printf("\n");
		}
	}
}