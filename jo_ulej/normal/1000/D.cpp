#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353LL;
const int MAX_N = 2666;

ll dp[MAX_N], a[MAX_N], fact[MAX_N], inv_fact[MAX_N];
int n;

ll binpow(ll x, ll y)
{
	if(y <= 100)
	{
		ll ret = 1;

		for(int i = 0; i < y; ++i)
			ret = (ret * x) % mod;

		return ret;
	}

	ll ret = binpow(x, y / 2);
	ret = (ret * ret) % mod;

	if(y % 2 != 0)
		ret = (ret * x) % mod;

	return ret;
}

ll inverse(ll x)
{
	return binpow(x, mod - 2);
}

ll binomcoeff(ll x, ll y)
{
	if(y > x)
		return 0;

	if(y == x)
		return 1;

	ll ret = 1;

	ret = (ret * fact[x]) % mod;
	ret = (ret * inv_fact[y]) % mod;
	ret = (ret * inv_fact[x - y]) % mod;

	return ret;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	DBG(binomcoeff(1, 0));

	for(int i = n - 2; i >= 0; --i)
	{
		dp[i] = dp[i + 1];

		if(a[i] < 1)
			continue;

		for(int j = i + a[i]; j < n; ++j)
			dp[i] = (dp[i] + binomcoeff(j - i - 1, a[i] - 1) * (1 + dp[j + 1])) % mod;
	}

	cout << dp[0] << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;

	fact[0] = 1;
	inv_fact[0] = 1;

	for(int i = 1; i < MAX_N; ++i)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		inv_fact[i] = inverse(fact[i]);
	}

	solve();

	return 0;
}