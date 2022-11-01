#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 998244353;

int n, m;
set<int> graph[300001];
bool used[300001];
int color[300001];

int q[2];

ll pw(ll a, ll b)
{
	if(b == 0)
		return 1;

	if(b == 1)
		return a;

	if(b % 2 == 0)
	{
		ll r = pw(a, b / 2);

		return (r * r) % mod;
	}
	else
	{
		ll r = pw(a, b / 2);

		return (((r * r) % mod) * a) % mod;
	}
}

void dfs(int v, int c)
{
	used[v] = true;
	color[v] = c;

	++q[c];

	for(auto u: graph[v])
		if(!used[u])
			dfs(u, 1 - c);
}

int main(int argc, char** argv)
{
	FAST_IO
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		ll ans = 1;
		cin >> n >> m;
		vector<pair<int, int>> edges;

		for(int i = 0; i < n; ++i)
			graph[i].clear();

		for(int j = 0; j < m; ++j)
		{
			int u, v;
			cin >> u >> v;
			--u, --v;

			graph[u].insert(v);
			graph[v].insert(u);
			edges.emplace_back(u, v);
		}

		for(int i = 0; i < n; ++i)
			used[i] = false;

		for(int v = 0; v < n; ++v)
		{
			if(!used[v])
			{
				q[0] = q[1] = 0;
				dfs(v, 0);

				ans = (ans * ((pw(2, q[0]) + pw(2, q[1])) % mod)) % mod;
			}
		}

		bool correct = true;

		for(auto edge: edges)
			correct = correct && (color[edge.first] + color[edge.second] == 1);

		if(correct)
			cout << ans << endl;
		else
			cout << "0" << endl;
	}

    return 0;
}