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

void solve()
{
	int n, m, k; cin >> n >> m >> k;
	vector<pll> a, b;

	for(int i = 0; i < n; ++i)
	{
		ll val; cin >> val;
		a.emplace_back(val, i);
	}

	sort(a.rbegin(), a.rend());

	for(int i = 0; i < k * m; ++i)
		b.emplace_back(a[i].second, a[i].first);

	sort(b.begin(), b.end());

	ll sm = 0;

	for(auto el: b)
		sm += el.second;

	cout << sm << endl;

	for(int i = m; i < b.size(); i += m)
		cout << b[i].first << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}