//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e5 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, s;
vector<vi> g;
map<pair<int, int>, int> pr;
int c = 0;
set<pair<int, int>> ss;
void dfs(int v = s, int p = 0) {
	ss.insert({v, p});
	for(auto i : g[v]) {
		if(!pr.count({i, p^1})) {
			pr[{i, p^1}] = v;
			dfs(i, p^1);
		} else if(ss.count({i, p^1}))
			c = 1;
	}
	ss.erase({v, p});
	if(g[v].size()==0&&p==1) {
		cout << "Win\n";
		vi ans;
		while(v!=-1) {
			ans.pb(v);
			v = pr[{v, p}], p ^= 1;
		}
		reverse(all(ans));
		for(auto i : ans) cout << i << " ";
		exit(0);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n+1);
	for(int f, t, i = 1; i <= n; i++) {
		cin >> t;
		for(int j = 0; j < t; j++)
			cin >> f, g[i].pb(f);
	}
	cin >> s;
	pr[{s, 0}] = -1;
	dfs();
	cout << (c?"Draw":"Lose");
}