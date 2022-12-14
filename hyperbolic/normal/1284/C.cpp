#include <stdio.h>

long long int fact[2500010];
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	fact[0] = 1;
	for(int i=1;i<=a;i++) fact[i] = i*fact[i-1], fact[i]%=b;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int S = (a-i+1);
		ans += (((S*S)%b)*fact[i])%b*fact[a-i]%b;
		ans %= b;
	}
	printf("%lld",ans);
}