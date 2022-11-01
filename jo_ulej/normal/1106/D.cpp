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
const int MAX_N = 100111;

vector<int> g[MAX_N], ans;
bool used[MAX_N];
int n, m;

void solve()
{
	cin >> n >> m;

	set<pii> edges;

	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;

		if(u > v)
			swap(u, v);

		if(u != v)
			edges.insert(make_pair(u, v));
	}

	for(auto e: edges)
	{
		int u = e.first, v = e.second;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 0; i < n; ++i)
	{
		if(!g[i].empty())
			sort(g[i].begin(), g[i].end());
	}

	set<int> s;
	s.insert(0);

	while(!s.empty())
	{
		auto it = s.begin();
		used[*it] = true;
		ans.push_back(*it);

		for(auto u: g[*it])
			if(!used[u])
				s.insert(u);

		s.erase(it);
	}

	for(auto el: ans)
		cout << el + 1 << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}