#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
	int r, p, col;
	ll sz[2];
	vi ch;
	void init(int i) {
		sz[0] = 1, sz[1] = 0;
		r = 0;
		p = i;
		col = 0;
//		ch.pb(i);
	}
};
struct dsu {
	ll ans = 0;
	vector<node> v;
	void init(int n) {
		v.resize(n + 1);
		for (int i = 0; i <= n; i++)
			v[i].init(i);
	}
	int par(int i) {
		if (v[i].p == i)
			return i;
		return v[i].p = par(v[i].p);
	}
	void unite(int i, int j, int same) {
		int rev = (v[i].col == v[j].col)^same;
		i = par(i), j = par(j);
		if (i == j)
			return;
		if (v[i].r < v[j].r)
			swap(i, j);
		v[j].p = i;
		v[i].r += v[i].r == v[j].r;
		ans -= get(i);
		ans -= get(j);
		v[i].sz[0] += v[j].sz[rev];
		v[i].sz[1] += v[j].sz[1^rev];
		if(rev)
			dfs(j);
		v[i].ch.pb(j);
//		for(auto x : v[j].ch) {
//			v[i].ch.pb(x);
//			v[x].col^=rev;
//		}
//		v[j].ch.clear();
		ans += get(i);
	}
	void dfs(int x) {
		v[x].col^=1;
		for(auto i : v[x].ch)
			dfs(i);
	}
	ll get(int i){
		return min(v[i].sz[0], v[i].sz[1]);
	}
};
int n, k;
vi g[maxn];
string  s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> s;
	for(int t, s, i = 0; i < k; i++) {
		cin >> s;
		for(int j = 0; j < s; j++) {
			cin >> t;
			g[t].pb(i+1);
		}
	}
	dsu d;
	d.init(k);
	for(int i = 1; i <= n; i++) {
		if(s[i-1]=='1') {
			if(g[i].size()==2) {
				d.unite(g[i][0], g[i][1], 1);
			} else if(g[i].size()==1) {
				d.ans -= d.get(d.par(g[i][0]));
				d.v[d.par(g[i][0])].sz[d.v[g[i][0]].col]+=1000000;
				d.ans += d.get(d.par(g[i][0]));
			}
		} else {
			if(g[i].size()==2) {
				d.unite(g[i][0], g[i][1], 0);
			} else if(g[i].size()==1) {
				d.ans -= d.get(d.par(g[i][0]));
				d.v[d.par(g[i][0])].sz[d.v[g[i][0]].col^1]+=1000000;
				d.ans += d.get(d.par(g[i][0]));
			}
		}
//		for(int i = 1; i <= k; i++) {
//			if(d.par(i)==i) {
//				cout << i << " " << d.v[i].sz[0] << " " << d.v[i].sz[1] << " " << d.v[i].ch.size() << "\n";
//			}
//		}
		cout << d.ans << "\n";
	}
}