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

const ll mod = 1e7 + 9;

void solve()
{
	int n;
	long double s;
	vector<int> deg;

	cin >> n >> s;
	deg.resize(n, 0);

	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;

		++deg[u];
		++deg[v];
	}

	int L = 0;

	for(auto x: deg)
		if(x == 1)
			++L;

	long double ans = (2.0 * s) / (long double)L;

	cout << fixed << setprecision(18) << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}