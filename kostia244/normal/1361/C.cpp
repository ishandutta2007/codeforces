#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int maxn = 1<<20, mod = 1e9 + 7;
int n, cnt[maxn];
vi eulerWalk(vector<vector<pi>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<pair<int, int>> re(n);
	for(auto &i : re) {
		cin >> i.first >> i.second;
	}
	for(int i = 20; i >= 0; i--) {
		int msk = (1<<i) - 1, I = 0;
		vector<vector<pi>> g(msk + 1);
		for(auto [f, t] : re) {
			f &= msk, t &= msk;
			g[f].pb({t, I});
			g[t].pb({f, I});
			I++;
		}
		int s = 0;
		while(g[s].empty()) s++;
		vi ans = eulerWalk(g, n, s);
		if(ans.size()) {
			map<pair<int, int>, vi> id;
			int I = 0;
			for(auto [f, t] : re) {
				f &= msk, t &= msk;
				I++;
				id[{f, t}].pb(I);
				id[{t, f}].pb(-I);
			}
			cout << i << "\n";
			vi used(n+3, 0);
			vi res;
			for(int i = 1; i < ans.size(); i++) {
				int f = ans[i-1],  t = ans[i];
				while(used[abs(id[{f, t}].back())]) id[{f, t}].pop_back();
				int x  = id[{f, t}].back();
				used[abs(x)] = 1;
				id[{f, t}].pop_back();
				if(x > 0) res.pb(2*x-1), res.pb(2*x);
				else res.pb(2*-x), res.pb(2*-x-1);
			}
			//for(int i = 2;  i < res.size(); i+=2) cout << res[i-1] << " " << res[i] << " : " << (_check[res[i]]^_check[res[i-1]]) << '\n';
			for(auto i : res) cout << i << " ";
			return 0;
		}
	}
}