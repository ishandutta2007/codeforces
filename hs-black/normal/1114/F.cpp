/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ll long long
#define MP make_pair
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar())
		if (c == '-') f = -1;
	for (; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + (c ^ '0');
	x *= f;
}

template <typename T>
void write(T x, char ed = '\n') {
	static short st[30], tp = 0;
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar('0' | st[tp--]);
	putchar(ed);
}

template <typename T>
void Mx(T &x, T y) { x < y && (x = y); }
template <typename T>
void Mn(T &x, T y) { x > y && (x = y); }

const int N = 400500;
const int P = 1e9 + 7;

#define ls p << 1
#define rs ls | 1
ll tm[N<<2], tt[N<<2], mul[N<<2], t[N<<2], val[N], a[N];

ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

void build(int p, int l, int r) {
	tm[p] = 1, tt[p] = 0;
	if (l == r) return t[p] = val[a[l]], mul[p] = a[l], void();
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	t[p] = t[ls] | t[rs], mul[p] = mul[ls] * mul[rs] % P;
}

inline void Tag(int p, int len, ll x, ll tx) {
	mul[p] = mul[p] * fpw(x, len) % P, t[p] |= tx;
	tt[p] |= tx, tm[p] = tm[p] * x % P;
}

void spread(int p, int l, int r, int mid) {
	Tag(ls, mid - l + 1, tm[p], tt[p]);
	Tag(rs, r - mid, tm[p], tt[p]);
	tm[p] = 1, tt[p] = 0;
}

void change(int p, int l, int r, int L, int R, ll x, ll tx) {
	if (L <= l && r <= R) return Tag(p, r - l + 1, x, tx);
	int mid = (l + r) >> 1; spread(p, l, r, mid);
	if (L <= mid) change(ls, l, mid, L, R, x, tx);
	if (mid < R) change(rs, mid + 1, r, L, R, x, tx);
	t[p] = t[ls] | t[rs], mul[p] = mul[ls] * mul[rs] % P;
}

pair<ll, ll> query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return MP(mul[p], t[p]);
	int mid = (l + r) >> 1; spread(p, l, r, mid);
	pair<ll, ll> res(1, 0), tp;
	if (L <= mid) tp = query(ls, l, mid, L, R), res.fi = res.fi * tp.fi % P, res.se |= tp.se;
	if (mid < R) tp = query(rs, mid + 1, r, L, R), res.fi = res.fi * tp.fi % P, res.se |= tp.se;
	return res;
}

ll inv[N], prime[N], tot;
ll Inv(ll tx) {
	ll ans = 1;
	for (int i = 0;i < tot; i++)
		if (tx >> i & 1) ans = ans * inv[prime[i+1]] % P * (prime[i+1] - 1) % P;
	return ans;
}

int n, q;
char s[432];
int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(q);
	for (int i = 2;i <= 300; i++) {
		if (val[i]) continue;
		prime[++tot] = i;
		for (int j = i;j <= 300; j += i)
			val[j] |= (1ll << (tot - 1));
	}
	for (int i = 1;i <= n; i++) read(a[i]);
	build(1, 1, n), inv[0] = inv[1] = 1;
	for (int i = 2;i <= 300; i++)
		inv[i] = inv[P % i] * (P - P / i) % P;
	while (q--) {
		scanf ("%s", s); int l, r, x;
		if (s[0] == 'M') read(l), read(r), read(x), change(1, 1, n, l, r, x, val[x]);
		else {
			read(l), read(r);
			pair<ll, ll> tp = query(1, 1, n, l, r);
			write(tp.fi * Inv(tp.se) % P);
		}
	}
	return 0;
}

/*

10 8
1 1 7 1 1 6 1 1 5 3
T 3 3
M 1 5 2
T 6 6
M 2 9 3
T 4 6  
M 3 6 6
M 1 5 2
T 3 4


*/