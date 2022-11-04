#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi a, b, c;
vvi g;
ll ans = 0;

pair<int, int> dfs(int v, int p, int max1) {
	pair<int, int> res = {0, 0};
	if(b[v] == 0 && c[v] == 1) {
		++res.first;
	}
	if(b[v] == 1 && c[v] == 0) {
		++res.second;
	}
	for(int u : g[v]) {
		if(u == p) {
			continue;
		}
		auto p1 = dfs(u, v, min(max1, a[v]));
		res.first += p1.first;
		res.second += p1.second;
	}
	if(a[v] < max1) {
		int res1 = min(res.first, res.second);
		ans += (ll)res1 * 2 * a[v];
		res.first -= res1;
		res.second -= res1;
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    g.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--u;
    	--v;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    auto p = dfs(0, -1, 1000000001);
    if(p.first != 0 || p.second != 0) {
    	cout << -1;
    	return 0;
    }
    cout << ans;
}