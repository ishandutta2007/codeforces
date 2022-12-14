#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int L = x[1], R = x[1], ans = 0;
		for(int i=2;i<=a;i++)
		{
			L = L<x[i]?L:x[i];
			R = R>x[i]?R:x[i];
			if(R-L>2*b)
			{
				ans++;
				L = R = x[i];
			}
		}
		printf("%d\n",ans);
	}
}