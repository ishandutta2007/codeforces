#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif

#define gcd __gcd
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll stupid(ll a)
{
	ll ret = -LL_INF;

	for(ll b = 1LL; b < a; ++b)
		ret = max(ret, gcd(a ^ b, a & b));

	return ret;
}

void solve()
{
	ll a;
	cin >> a;

	ll cnt = 0;
	ll temp = a;

	while(temp > 0)
		++cnt, temp >>= 1LL;

	ll ans = (1LL << cnt) - 1;

	if(ans == a)
	{
		ans = -LL_INF;

		for(ll d = 1; d * d <= a; ++d)
		{
			if(a % d == 0)
			{
				ans = max(ans, d);

				if(a / d != a)
					ans = max(ans, a / d);
			}
		}
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;

	int t;
	cin >> t;

	for(; t > 0; --t)
		solve();

	return 0;
}