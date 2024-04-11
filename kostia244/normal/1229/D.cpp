#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k;
map<vector<int>, int> ptoi;
int M[120][120];
int que[120], sz;
struct basis { 
	bitset<128> vis, b;
	basis() {vis[0] = 1;}
	void apply(int x) {
		if(vis[x]) return;
		b[x] = 1;
		sz = 0;
		for(int i = 0; i < 120; i++) if(vis[i])
			if(!vis[M[i][x]]) {
				que[sz] = M[i][x];
				vis[que[sz++]] = 1;
			}
		int pos = 0;
		while(pos < sz) {
			int v = que[pos++];
			for(int i = b._Find_first(); i < 128; i = b._Find_next(i)) 
				if(!vis[M[v][i]]) {
					que[sz] = M[v][i];
					vis[que[sz++]] = 1;
				}
		}
	}
};
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	{
	int id = 0;
	vector<int> t(k), a, b, c(k);
	iota(all(t), 1);
	a = t;
	do {
		ptoi[a] = id++;
	} while(next_permutation(all(a)));
	a = t;
	do {
		b = t;
		do {
			for(int i = 0; i < k; i++) c[i] = b[a[i]-1];
			M[ptoi[a]][ptoi[b]] = ptoi[c];
		} while(next_permutation(all(b)));
	} while(next_permutation(all(a)));
	}
	ll ans = 0;
	vector<pair<int, basis>> st;
	for(int v, i = 0; i < n; i++) {
		vector<int> _t(k);
		for(auto &i : _t) cin >> i;
		v = ptoi[_t];
		st.push_back({i, basis()});
		for(auto &i : st) i.second.apply(v);
		vector<pair<int, basis>> nw;
		for(int i = 0; i < st.size(); i++)
			if(i+1 == st.size() || st[i].second.vis != st[i+1].second.vis) nw.push_back(st[i]);
		st = nw;
		int lst = -1;
		for(auto &[p, b] : st) {
			ans += (p-lst)*b.vis.count();
			lst = p;
		}
	}
	cout << ans << '\n';
}