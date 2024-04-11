#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 4e5 + 555;
namespace treemx {
ll val[maxn], p[maxn][19], mx[maxn][19];
int add(int v, int a, int w) {
	val[v] = w;
	p[v][0] = a;
	mx[v][0] = val[a];
	for(int i = 1; i < 19; i++) {
		p[v][i] = p[p[v][i-1]][i-1];
		mx[v][i] = max(mx[p[v][i-1]][i-1], mx[v][i-1]);
	}
	for(int i = 19; i--;) {
		if(p[v][i]&&mx[v][i]<w) v = p[v][i];
	}
	if(p[v][0]) v = p[v][0];
	else v = 0;
	return v;
}
};
namespace treesm {
ll val[maxn], p[maxn][19], sm[maxn][19];
void add(int v, int a, int w) {
	val[v] = w;
	p[v][0] = a;
	sm[v][0] = val[a];
	for(int i = 1; i < 19; i++) {
		p[v][i] = p[p[v][i-1]][i-1];
		sm[v][i] = sm[p[v][i-1]][i-1] + sm[v][i-1];
	}
}
int qry(int v, ll x) {
	if(x<val[v]) return 0;
	x-=val[v];
	int ans = 1;
	for(int i = 19; i--;) {
		if(p[v][i]&&sm[v][i]<=x) {
			ans += 1<<i;
			x -= sm[v][i];
			v = p[v][i];
		}
	}
	return ans;
}
};
int q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	ll t, l, r, lst = 0, cc = 2;
	while(q--) {
		cin >> t >> l >> r;
		l^=lst, r^=lst;
		if(t==1) {
			t = treemx::add(cc, l, r);
			treesm::add(cc, t, r);
			cc++;
		} else {
			cout << (lst=treesm::qry(l, r)) << '\n';
		}
	}
}