#include <stdio.h>

long long int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		long long int L = x[1], R = x[1];
		for(int i=1;i<=a-1;i++)
		{
			L = L>x[i]?L:x[i];
			R = R<x[i]+b-1?R:x[i]+b-1;
			if(L>R)
			{
				printf("NO\n");
				goto u;
			}
			
			L-=(b-1);
			R+=(b-1);
		}
		if(L<=x[a]&&x[a]<=R) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}