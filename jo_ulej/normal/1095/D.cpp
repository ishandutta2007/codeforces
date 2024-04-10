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

const ll mod = 1e7 + 9;

vector<int> graph[200000];
bool used[200000];
int n;

vector<int> ans;

void dfs(int v)
{
	used[v] = true;
	ans.push_back(v + 1);

	for(auto u: graph[v])
		for(auto w: graph[u])
			if((graph[v][0] == w || graph[v][1] == w) && !used[u])
				dfs(u);
}

void solve()
{
	cin >> n;

	for(int v = 0; v < n; ++v)
	{
		int u, w;

		cin >> u >> w;
		--u, --w;

		graph[v].push_back(u);
		graph[v].push_back(w);
	}

	dfs(0);

	for(auto x: ans)
		cout << x << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}