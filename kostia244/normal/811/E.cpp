#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<17;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
	int lst = -1, cc = 0;
	array<int, 10> l, r;
	node() {}
	node(int x, array<int, 10> y) : lst(x), l(y), r(y) {
		cc = 1;
		for(int i = 1; i < 10; i++) if(y[i] != y[i-1]) cc++;
	}
};
int n, m, q;
array<int, 10> f[maxn], F[maxn];
node st;
int p[40];
int get(int v) {
	return p[v]>-1?p[v]=get(p[v]):v;
}
int unite(int x, int y) {
	x = get(x), y = get(y);
	if(x == y) return 0;
	if(rng()&1) swap(x, y);
	p[x] = y;
	return 1;
}
node res;
node merge(const node &l, const node &r) {
	if(l.lst == -1) return r;
	if(r.lst == -1) return l;
	memset(p, -1, sizeof p);
	res.cc = l.cc + r.cc;
	for(int i = 0; i < 10; i++) {
		if(F[l.lst][i] == F[l.lst+1][i]) res.cc -= unite(l.r[i], 19+r.l[i]);
	}
	res.l = l.l;
	res.r = r.r;
	for(int i = 0; i < 10; i++) {
		res.l[i] = get(l.l[i]);
		res.r[i] = get(19+r.r[i]);
	}
	memset(p, 0, sizeof p);
	for(int i = 0; i < 10; i++) p[res.l[i]] = p[res.r[i]] = 1;
	for(int c = 0, i = 0; i < 40; i++) if(p[i]) p[i] = c++;
	for(int i = 0; i < 10; i++) {
		res.l[i] = p[res.l[i]];
		res.r[i] = p[res.r[i]];
	}
	res.lst = r.lst;
	return res;
}
node tr[2*maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> q;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < m; j++) {
			if(i < n)
				cin >> F[j][i];
			else F[j][i] = -1;
		}
	for(int i = 0; i < m; i++) {
		f[i] = F[i];
		for(int j = 0, p = -1, c = -1; j < 10; j++) {
			if(f[i][j] == p) f[i][j] = c;
			else p = f[i][j], f[i][j] = ++c;
		}
		tr[m+i] = node(i, f[i]);
	}
	for(int i = m; i-->1;) tr[i] = merge(tr[2*i], tr[2*i+1]);
	while(q--) {
		int l, r;
		cin >> l >> r;
		node L, R;
		//cout << l+m-1 << " " << r+m << endl;
		for(l += m-1, r += m; l < r; l>>=1, r>>=1) {
			if(l&1) L = merge(L, tr[l++]);// cout << tr[l-1].lst << endl;
			if(r&1) R = merge(tr[--r], R);// cout << tr[r].lst << endl;
		}
		L = merge(L, R);
		cout << L.cc - (n!=10) << '\n';
	}
}
//?VK
//??V
//K?