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

void solve()
{
	int n;
	vector<ll> cnt;
	int j = 0;

	cin >> n;
	cnt.resize(n + 1, 0);
	cnt[0] = 1;

	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		vector<int> divs;

		for(int d = 1; d * d <= x; ++d)
		{
			if(x % d == 0)
			{
				divs.push_back(d);

				if(x / d != d)
					divs.push_back(x / d);
			}
		}

		sort(divs.begin(), divs.end());
		reverse(divs.begin(), divs.end());

		for(auto d: divs)
			if(d <= n)
				cnt[d] = (cnt[d] + cnt[d - 1]) % mod;
	}

	ll ans = 0;

	for(int len = 1; len <= n; ++len)
		ans = (ans + cnt[len]) % mod;

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}