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
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		x[b+1] = 0;
		int p = 1;
		int ans = 0;
		while(p+2<=b+1)
		{
			if(x[p+1]==x[p+2]+1) p = p+2;
			else ans++,p = p+1;
		}
		printf("%d\n",ans);
	}
}