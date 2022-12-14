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
		int S = 0;
		for(int i=1;i<=a;i++) S += x[i];
		if(S<b)
		{
			printf("-1\n");
			continue;
		}
		S = 0;
		int p = 0;
		int ans = 0;	
		for(int i=1;i<=a;i++)
		{
			S -= x[i-1];
			while(p<a && S+x[p+1]<=b) S += x[++p];
			ans = ans>(p-i+1)?ans:(p-i+1);
		}
		printf("%d\n",a-ans);
	}
}