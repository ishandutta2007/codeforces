#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;

int mx[N << 2], mn[N << 2], g[N << 2], c[N], a[N], b[N];
int n, m, op, l, r, x;

void add(int pos, int val) {
	for(; pos <= n; pos += pos & -pos)
		c[pos] += val;
}

int ask(int pos) {
	int ans = 0;
	for(; pos; pos -= pos & -pos)
		ans += c[pos];
	return ans;
}

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
	g[rt] = __gcd(g[rt << 1], g[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	if(l == r) {
		mx[rt] = mn[rt] = g[rt] = b[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		mx[rt] += val;
		mn[rt] += val;
		g[rt] += val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int querymax(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return max(abs(mn[rt]), abs(mx[rt]));
	}
	int mid = l + r >> 1, ans = 0;
	if(L <= mid)
		ans = max(ans, querymax(rt << 1, l, mid, L, R));
	if(R > mid)
		ans = max(ans, querymax(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int querygcd(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return g[rt];
	}
	int mid = l + r >> 1, ans = 0;
	if(L <= mid)
		ans = __gcd(ans, querygcd(rt << 1, l, mid, L, R));
	if(R > mid)
		ans = __gcd(ans, querygcd(rt << 1 | 1, mid + 1, r, L, R));
	return abs(ans);
}
void cz(int op,int x){
	l=1,r=n;
	if(op == 1) {
		add(l, x);
		update(1, 1, n, l, x);
		if(r != n) {
			add(r + 1, -x);
			update(1, 1, n, r + 1, -x);
		}
	}
	else {
		int a = ask(l), b;
		if(l == r)
			b = 0;
		else
			b = querygcd(1, 1, n, l + 1, r);
		printf("%lld\n", __gcd(a, b));
	}
}
signed main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		add(i, a[i] - a[i - 1]);
		b[i] = a[i] - a[i - 1];
	}
	build(1, 1, n);
	while(m--) {
		scanf("%lld", &x);
		cz(1,x);
		cz(2,x);
		cz(1,-x);
	}
	return 0;
}