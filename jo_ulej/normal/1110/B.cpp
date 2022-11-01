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

#define int ll

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> b(n), a(n - 1);

	for(auto& el: b)
		cin >> el;

	for(int i = 0; i < n - 1; ++i)
		a[i] = b[i + 1] - b[i];

	sort(a.rbegin(), a.rend());

	int ans = b[n - 1] - b[0] + 1;

	for(int i = 0; i < n - 1 && i < k - 1; ++i)
		ans -= a[i] - 1;

	cout << ans << endl;
}

#undef int

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}