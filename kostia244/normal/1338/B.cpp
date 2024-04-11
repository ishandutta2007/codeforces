#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vi g[maxn];
int cnt[2] = {0, 0};
int mx;
void dfs(int v, int p, int h) {
	if(g[v].size()==1)
		cnt[h]++;
	int cntl = 0;
	for(auto i : g[v]) {
		if(i == p) continue;
		dfs(i, v, h^1);
		if(g[i].size()==1) cntl++;
	}
	if(cntl) mx -= cntl-1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	mx = n-1;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int r = -1;
	for(int i = 1; i <= n; i++) if(g[i].size()>1) r = i;
	dfs(r,r,0);
	int mn = 1;
	if(cnt[0]&&cnt[1]) mn = 3;
	cout << mn << " " << mx << '\n';
	return 0;
}