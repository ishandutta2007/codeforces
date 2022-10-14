#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e4 + 455;
const int mod = 1e9 + 7;
int n, m;
vi h, cl, cl2, cnt, mx;
ll cur = 0;
pi ans;
vector<vi> g;
void findh(int v, int p) {
	if (cnt[v]) {
		cl[v] = 0;
	}
	for (auto i : g[v]) {
		if (i == p)
			continue;
		h[i] = h[v] + 1;
		findh(i, v);
		int t = cl[i]+1;
		if(cl[v]<t) {
			cl2[v] = cl[v], cl[v] = t;
		} else if(cl2[v]<t) {
			cl2[v] = t;
		}
		cnt[v] += cnt[i];
	}
	cur+=cnt[v]>0;
}
void go(int v, int p) {
	if(!cnt[v]) return;
	if(v!=p) {
		int t = 1+(cl[v]+1==cl[p]?cl2[p]:cl[p]);
		if(cl[v]<t) {
			cl2[v] = cl[v], cl[v] = t;
		} else if(cl2[v]<t) {
			cl2[v] = t;
		}
	}
//	cout << v << " " << cl[v] << " " << cl2[v] << "\n";
	ans = min(ans, {cur-cl[v], v});
	for(auto i : g[v]) {
		if(i==p) continue;
		go(i, v);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	h.resize(n + 1);
	cl.resize(n + 1, -(1<<20));
	cl2.resize(n + 1, -(1<<20));
	mx.resize(n + 1);
	cnt.resize(n + 1);
	int l;
	for (int t, i = 0; i < m; i++)
		cin >> t, cnt[t] = 1, l = t;
	findh(l, l);
//	cout << cur << "\n";
	cur=(cur-1)*2;
//	cout << cur << "\n";
	ans = {cur, l};
	go(l, l);
	cout << ans.second << "\n" << ans.first;
}