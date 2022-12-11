#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, a[N];
struct Base {
	int ba[32];
	void clear() {
		fill(ba, ba + 32, 0);
	}
	void insert(int x) {
		for(int i = 30; ~ i; i --) if(x >> i & 1) {
			if(!ba[i]) {
				ba[i] = x; return ;
			}
			x ^= ba[i];
		}
	}
	int size() {
		int ans = 0;
		for(int i = 0; i < 32; i ++) ans += ba[i] > 0;
		return ans;
	}
} s[N << 2];
Base operator + (Base a, Base b) {
	Base ans; ans.clear();
	for(int i = 0; i < 31; i ++) if(a.ba[i]) ans.insert(a.ba[i]);
	for(int i = 0; i < 31; i ++) if(b.ba[i]) ans.insert(b.ba[i]);
	return ans;
}
struct Bit {
	int a[N];
	void insert(int x, int y) {
		for(; x <= n; x += x & (-x)) {
			a[x] ^= y;
		}
	}
	int query(int x) {
		int ans = 0;
		for(; x >= 1; x &= x - 1){
			ans ^= a[x];
		}
		return ans;
	}
} bit;
void build(int u, int l, int r){
	if(l == r) {
		s[u].insert(a[l]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	s[u] = s[u << 1] + s[u << 1 | 1];
}
void modify(int u, int l, int r, int p, int v) {
	if(l == r) {
		s[u].clear(); s[u].insert(a[l] ^= v);
		bit.insert(l, v);
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) modify(u << 1, l, mid, p, v);
	else modify(u << 1 | 1, mid + 1, r, p, v);
	s[u] = s[u << 1] + s[u << 1 | 1];
}
Base query(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		return s[u];
	}
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(u << 1, l, mid, ql, qr);
	if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
	return query(u << 1, l, mid, ql, mid) + query(u << 1 | 1, mid + 1, r, mid + 1, qr);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	for(int i = 1; i <= n; i ++) bit.a[i] = a[i] ^ a[i & (i - 1)]; 
	for(int i = n; i >= 1; i --) a[i] ^= a[i - 1];
	build(1, 1, n);
	for(int i = 1; i <= q; i ++) {
		int op, l, r, k;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			scanf("%d", &k);
			modify(1, 1, n, l, k);
			if(r != n) modify(1, 1, n, r + 1, k);	
		} else {
			Base ans = l != r ? query(1, 1, n, l + 1, r) : s[0];
			ans.insert(bit.query(l));
			printf("%lld\n", 1ll << ans.size());
		}
	}
	return 0;
}