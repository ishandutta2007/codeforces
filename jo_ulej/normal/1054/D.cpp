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

const ll mod = 1e9 + 7;

int k;

int xorm(int a, int b)
{
	return (a ^ b) & ((1 << k) - 1);
}

int inv(int a)
{
	return (~a) & ((1 << k) - 1);
}

void solve()
{
	int n;
	vector<int> prefxor;

	cin >> n >> k;
	prefxor.resize(n + 1);

	for(int i = 0; i < n; ++i)
	{
		int dummy;
		cin >> dummy;

		prefxor[i + 1] = xorm(dummy, prefxor[i]);
	}

	map<int, ll> cnt;

	for(auto& el: prefxor)
	{
		el = min(el, inv(el));

		if(cnt.find(el) == cnt.end())
		{
			cnt.insert(make_pair(el, 1));
		}
		else
		{
			++cnt[el];
		}
	}

	ll m = (ll)n;
	ll ans = ((m + 1) * m) / 2;

	for(auto el: cnt)
	{
		ll a = el.second / 2;
		ll b = el.second / 2 + el.second % 2;

		ans -= a * (a - 1) / 2;
		ans -= b * (b - 1) / 2;
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}