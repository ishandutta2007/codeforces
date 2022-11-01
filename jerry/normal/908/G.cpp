#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

bool vi[12][705][705][2];
ll dp[12][705][705][2];
char x[800];
int n;
ll ans;

ll slv(int v, int at, int rem, int eq)
{
	if (at == n) return rem==0;
	if (vi[v][at][rem][eq]) return dp[v][at][rem][eq];
	vi[v][at][rem][eq] = true;
	for (int i = 0;i < 10 && (!eq || i+'0' <= x[at]);i++) dp[v][at][rem][eq] += slv(v, at+1, max(0, rem-(i>=v)), eq&(i+'0'==x[at]));
	return dp[v][at][rem][eq] %= MOD;
}

int main()
{
	scanf("%s", x); n = strlen(x);
	for (int v = 1;v < 10;v++)
	{
		ll ex = v;
		for (int p = 0;p < n;p++)
		{
			ans += (slv(v, 0, p+1, 1)-slv(v+1, 0, p+1, 1))*ex;
			ans %= MOD;
			ex = (ex*10)%MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}