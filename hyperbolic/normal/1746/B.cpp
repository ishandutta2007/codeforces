#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int L = 1, R = a;
		int ans = 0;
		while(1)
		{
			while(L<=a && x[L]==0) L++;
			while(R>=1 && x[R]==1) R--;
			if(R<L) break;
			ans++;
			int t = x[L];
			x[L] = x[R];
			x[R] = t;
		}
		printf("%d\n",ans);
	}
}