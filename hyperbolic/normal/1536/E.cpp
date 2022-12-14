#include <stdio.h>
#define MOD 1000000007

char x[2010][2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		int control = 1;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='0') control = 0;
		
		long long int ans = 1;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='#') ans*=2, ans %= MOD;
		ans += (MOD-control), ans %= MOD;
		printf("%lld\n",ans);
	}
}