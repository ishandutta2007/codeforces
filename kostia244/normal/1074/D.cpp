#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 24100000;
struct UF {
	int32_t e[maxn];
	UF() {for(int i = 0; i < maxn; i++) e[i] = -1;}
	bool connected(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
} d;
map<int, int> V;
int F(int x) {
	if(V.count(x)) return V[x];
	int t = V.size()+1;
	while(t >= maxn);
	//cout << t << '\n';
	return V[x] = t;
}
#define get(x, i) (((x)>>(i))&1)
int find(int l, int r) {	
	int bad = 0, ans = 0;
	for(int i = 0; i < 30; i++) {
		int z = d.connected(l + 2*i, r + 2*i);
		int o = d.connected(l + 2*i + 1, r + 2*i);
		bad |= z == o;
		if(o) ans ^= 1<<i;
	}
	return bad?-1:ans;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int q, t, l, r, x, ans = 0;
	for(cin >> q; q--;) {
		cin >> t >> l >> r;
		if((l ^= ans) > (r ^= ans)) swap(l, r);
		--l;
		l = F(l), r = F(r);
		l *= 60, r *= 60;
		if(t == 1) {
			cin >> x, x ^= ans;
			int t = find(l, r);
			if(t > -1 && t != x) continue;
			for(int i = 0; i < 30; i++) {
				d.unite(l + 2*i, r + 2*i + get(x, i));
				d.unite(l + 2*i + 1, r + 2*i + !get(x, i));
			}
		} else {
			ans = find(l, r);
			cout << ans << '\n';
			ans = abs(ans);
		}
	}
}