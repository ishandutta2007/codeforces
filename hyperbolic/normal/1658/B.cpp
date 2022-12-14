#include <stdio.h>
#define MOD 998244353

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==1) printf("0\n");
		else
		{
			int b = (a/2);
			long long int ans = 1;
			for(int i=1;i<=b;i++) ans*=i, ans%=MOD;
			ans*=ans, ans%=MOD;
			printf("%lld\n",ans);
		}
	}
}