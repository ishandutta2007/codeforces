//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, cnt = 1;
vector<vi> g;
vi c, a;
vpi dfs(int v) {
	vpi t;
	for(auto i : g[v]) {
		for(auto j : dfs(i))
			t.pb(j);
	}
	sort(all(t));
	if(c[v]>t.size()) {
		cout << "NO";
		exit(0);
	}
	if(c[v]==t.size()) {
		a[v] = ++cnt;
		t.pb({a[v], v});
	} else {
//		cout << "x";
		t.pb({a[v] = t[c[v]].first, v});
		int i = t.size()-2;
		while(i>=0&&t[i].first>=t[i+1].first) {
			t[i].first = a[t[i].second] = t[i].first+1;
			swap(t[i], t[i+1]);
			i--;
		}
		cnt = max(cnt, t.back().first);
	}
//	cout << v << " "<< a[v] <<"\n";
	return t;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n+1);
	c.resize(n+1);
	a.resize(n+1);
	for(int p, cc, i = 1; i <= n; i++) {
		cin >> p >> cc;
		c[i] = cc;
		g[p].pb(i);
	}
	dfs(g[0][0]);
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
}