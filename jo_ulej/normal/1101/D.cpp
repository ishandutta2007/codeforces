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
const int MAX_N = 200100;

vector<int> g[MAX_N];
ll a[MAX_N], n;
bool used[MAX_N];
set<ll> pr[MAX_N];

int dfs(int v, int prime, int& w)
{
	used[v] = true;
	pr[v].insert(prime);

	int best = 1;
	w = v;

	for(auto u: g[v])
	{
		if(used[u] || a[u] % prime != 0)
			continue;

		int tw;
		int nbest = dfs(u, prime, tw) + 1;

		if(nbest > best)
		{
			best = nbest;
			w = tw;
		}
	}

	used[v] = false;

	return best;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = 0;

	for(int v = 0; v < n; ++v)
	{
		ll num = a[v];

		if(num > 1)
			ans = max(ans, 1);

		while(num > 1)
		{
			ll p = 2;

			while(p * p <= num && num % p != 0)
				++p;

			if(num % p != 0)
				p = num;

			while(num % p == 0)
				num /= p;

			if(pr[v].find(p) != pr[v].end())
				continue;

			int w, w1;
			dfs(v, p, w);

			int dist = dfs(w, p, w1);
			DBG(v); DBG(w); DBG(w1);

			ans = max(ans, dist);
		}
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}