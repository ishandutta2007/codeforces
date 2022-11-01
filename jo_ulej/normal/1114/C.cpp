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

const ll mod = 1e9 + 7;

ll cnt(ll n, ll p)
{
	ll ret = 0;

	while(n / p > 0)
	{
		n /= p;
		ret += n;
	}

	return ret;
}

void solve()
{
	ll n, b;
	cin >> n >> b;

	ll ans = LL_INF;

	while(b > 1)
	{
		ll p = 2;

		while(p * p <= b && b % p != 0)
			++p;

		if(b % p != 0)
			p = b;

		ll cnt2 = 0;

		while(b % p == 0)
			b /= p, ++cnt2;

		ans = min(ans, cnt(n, p) / cnt2);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}