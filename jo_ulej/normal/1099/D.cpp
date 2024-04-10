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
const int MAX_N = 1e5 + 100;

vector<int> graph[MAX_N];
int n;
ll s[MAX_N], a[MAX_N], st_min[MAX_N];
bool used[MAX_N];
bool correct = true;

void dfs_st_min(int v)
{
	used[v] = true;

	if(s[v] != -1)
		st_min[v] = s[v];

	for(auto u: graph[v])
	{
		if(!used[u])
		{
			dfs_st_min(u);

			if(st_min[v] == -1)
				st_min[v] = st_min[u];
			else if(st_min[u] != -1)
				st_min[v] = min(st_min[v], st_min[u]);
		}
	}
}

void dfs(int v, int parent)
{
	used[v] = true;

	if(s[v] == -1)
	{
		if(st_min[v] != -1)
		{
			a[v] = st_min[v] - s[parent];	
		}
		else
		{
			a[v] = 0;
		}

		s[v] = s[parent] + a[v];
	}
	else
	{
		if(v == 0)
		{
			a[v] = s[v];
		}
		else
		{
			a[v] = s[v] - s[parent];
		}
	}

	if(a[v] < 0)
		correct = false;

	for(auto u: graph[v])
		if(!used[u])
			dfs(u, v);
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n - 1; ++i)
	{
		int u = i + 1, v;
		cin >> v;
		--v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i = 0; i < n; ++i)
		cin >> s[i];

	for(int i = 0; i < n; ++i)
		st_min[i] = -1;

	dfs_st_min(0);

	for(int i = 0; i < n; ++i)
		used[i] = false;

	dfs(0, -1);

	if(!correct)
	{
		cout << "-1" << endl;

		return;
	}

	ll ans = 0;

	for(int i = 0; i < n; ++i)
		ans += a[i];

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}