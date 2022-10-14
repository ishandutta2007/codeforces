#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<17, mod = 1000000007;
int n, h[maxn], pref[maxn], p[maxn];
vector<int> g[maxn], ord;
void find(int v) {
	for(auto &i : g[v]) {
		find(i);
		if(h[i]+1 > h[v]) {
			h[v] = h[i]+1;
			pref[v] = i;
		}
	}
	ord.push_back(v);
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	find(0);
	bitset<maxn> uwu;
	int T = 0;
	do {
		uwu[T] = 1;
		T = pref[T];
	} while(T);
	for(int i = 0; i < n; i++) pref[i] *= uwu[i];
	reverse(all(ord));
	vector<int> ops;
	for(auto i : ord) if(i && pref[p[i]] != i) {
		int t = pref[p[i]];
		pref[p[i]] = i;
		pref[i] = t;
		p[t] = i;
		ops.push_back(t);
	}
	reverse(all(ops));
	int t = 0;
	while(pref[t]) t++;
	ord.clear();
	while(true) {
		ord.push_back(t);
		if(t) t = p[t];
		else break;
	}
	reverse(all(ord));
	for(auto &i : ord) cout << i << " "; cout << '\n';
	cout << ops.size() << '\n';
	for(auto i : ops) cout << i << " "; cout << '\n';
}