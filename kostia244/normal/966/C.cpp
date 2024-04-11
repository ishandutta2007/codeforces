#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 6e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> bt[60];
int n;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(ll t, f, i = 0; i < n; i++) {
		cin >> t;
		f = 60;
		while(!(t&(1ll<<f))) f--;
		bt[f].push_back(t); 
	}
	vector<ll> cur;
	cur.push_back((1ll<<62)-1);
	for(int b = 60; b--;) {
		vector<ll> nw;
		int i = 0, j = 0;
		while(i < cur.size()) {
			if(j < bt[b].size() && (cur[i]^bt[b][j]) < cur[i]) nw.push_back(bt[b][j++]);
			nw.push_back(cur[i++]);
		}
		cur = nw;
	}
	cur.pop_back();
	if(cur.size() != n) return cout << "No\n", 0;
	cout << "Yes\n";
	for(auto &i : cur) cout << i << ' '; cout << '\n';
}