#include <stdio.h>
#include <set>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}


long long int x[200010],y[200010],sum[200010];
long long int func(int s, int t)
{
	long long int ans = sum[t-1] - sum[s-1];
	ans += MOD, ans %= MOD;
	ans *= inv(y[s-1]), ans %= MOD;
	long long int k = y[t-1];
	k *= inv(y[s-1]), k %= MOD;
	ans += (long long int)(MOD-1+k)*(s-1);
	ans %= MOD;
	ans += k*(t-s), ans %= MOD;
	ans *= inv(k), ans %= MOD;
	return ans;
}

std::set<int> S;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) x[i] *= inv(100), x[i] %= MOD;
	y[0] = 1;
	for(int i=1;i<=a;i++) y[i] = y[i-1]*x[i], y[i] %= MOD;
	for(int i=1;i<=a;i++)
	{
		long long int t = y[i-1]*(MOD+1-x[i]);
		t %= MOD;
		t *= i, t %= MOD;
		sum[i] = sum[i-1]+t, sum[i] %= MOD;
	}
	
	long long int ans = func(1,a+1);
	S.insert(1);
	S.insert(a+1);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		std::set<int> ::iterator it = S.lower_bound(c);
		if((*it)==c)
		{
			std::set<int> ::iterator it2 = it;
			it2--;
			it++;
			int s = (*it2), t = (*it);
			ans -= func(s,c), ans += MOD, ans %= MOD;
			ans -= func(c,t), ans += MOD, ans %= MOD;
			ans += func(s,t), ans %= MOD;
			S.erase(c);
		}
		else
		{
			std::set<int> ::iterator it2 = it;
			it2--;
			int s = (*it2), t = (*it);
			ans -= func(s,t), ans += MOD, ans %= MOD;
			ans += func(s,c), ans += MOD, ans %= MOD;
			ans += func(c,t), ans += MOD, ans %= MOD;
			S.insert(c);
		}
		printf("%lld\n",ans);
	}
}