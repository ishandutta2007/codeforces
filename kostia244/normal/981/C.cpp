#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<20;
using ll = long long;
int n;
vector<int> g[maxn];
vector<array<int, 2>> r;
int dfs(int v, int rt = 1, int par = -1) {
	int ret = v;
	for(auto &i : g[v]) if(i != par){
		int t = dfs(i, 0, v);
		if(t == -1) cout << "No\n", exit(0);
		if(rt) {
			r.push_back({v, t});
		} else {
			if(ret == v) ret = t;
			else return -1;
		}
	}
	return ret;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	int rt = 1;
	while(rt < n && g[rt].size() < 3) rt++;
	dfs(rt);
	cout << "Yes\n";
	cout << r.size() << '\n';
	for(auto [x, y]: r) cout << x << " " << y << '\n';
	
}