#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace  std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e6 + 66, sigma = 26;
int n, m, d[maxn], h[maxn];
vi l[maxn], g[maxn];
int compsum;
map<pi, int> id;
bitset<maxn> used;
vi fr;
void dfs(int v) {
	if(d[v]==-1) fr.pb(v);
	else compsum += d[v];
	l[h[v]].pb(v);
//	cout << v << " -- " << h[v] << "\n";
	for(auto i : g[v]) {
		if(h[i]) continue;
		h[i] = h[v] + 1;
		dfs(i);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> d[i];
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
		id[{f, t}] = id[{t,f}] =i+1;
	}
	for(int i = 1; i <= n; i++) {
		if(h[i]) continue;
		compsum = 0;
		fr.clear();
		h[i] = 1;
		dfs(i);
		if(compsum&1) {
			if(fr.empty()) return cout << -1, 0;
			d[fr.back()]=1;
			fr.pop_back();
		}
		for(auto j : fr) d[j] = 0;
	}
	vi ans;
	for(int __I = n; __I; __I--)
		for(auto i : l[__I]) {
			used.set(i);
			if(!d[i]) continue;
//			cout << i << " " << d[i] << "::\n";
			for(auto v : g[i]) {
				if(used.test(v)) continue;
//				cout << i << " " << v << "col " << d[v] << "\n";
				d[v]^=1;
//				cout << i << " " << v << "col " << d[v] << "\n";
				ans.pb(id[{i, v}]);
				break;
			}
		}
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i << " ";
}