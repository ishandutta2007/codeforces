#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MP make_pair
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int P = 998244353;
const int N = 200050;
struct mat {
	ll f[2][2];
	mat(void) { memset(f, 0, sizeof(f)); }
	ll * operator [] (int x) { return f[x]; }
	mat operator * (mat y) {
		mat t;
		for (int k = 0;k < 2; ++k)
			for (int i = 0;i < 2; ++i) {
				t[i][0] = (t[i][0] + f[i][k] * y[k][0]) % P;
				t[i][1] = (t[i][1] + f[i][k] * y[k][1]) % P;
			}
		return t;
	}
}M[N<<2];

ll fpw(ll x, ll mi = P - 2, ll res = 1) {
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

const int inv100 = fpw(100);

struct node { ll x, v, p; }poi[N];
struct Tm {
	ll x, y; int l, s;
	bool operator < (const Tm &i) const { return x * i.y < y * i.x; }
}q[N<<1];

#define ls p << 1
#define rs ls | 1
void build(int p, int l, int r) {
	if (l == r) {
		M[p][1][1] = M[p][0][1] = poi[l + 1].p;
		M[p][1][0] = M[p][0][0] = (P + 1 - poi[l + 1].p) % P;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	M[p] = M[ls] * M[rs];
}

void change(int p, int l, int r, int x, int c) {
	if (l == r) {
		if (c == 2) M[p][1][0] = 0;
		else {
			int t = poi[l].v > poi[l + 1].v;
			M[p][t][t] = 0;
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, c);
	else change(rs, mid + 1, r, x, c);
	M[p] = M[ls] * M[rs];
}

int ans, cnt, n;
int main() {
	read(n); 
	for (int i = 1;i <= n; ++i)
		read(poi[i].x), read(poi[i].v), read(poi[i].p), poi[i].p = poi[i].p * inv100 % P;
	if (n == 1) return write(0), 0;
	for (int i = 1;i < n; ++i) {
		node a = poi[i],  b = poi[i + 1];
		if (a.v != b.v) q[++cnt] = (Tm){b.x - a.x, abs(a.v - b.v), i, 1};
		q[++cnt] = (Tm){b.x - a.x, a.v + b.v, i, 2};
	}
	sort(q + 1, q + cnt + 1), build(1, 1, n - 1);

	ll pre = 1;
	for (int i = 1;i <= cnt; ++i) {
		ll v = q[i].x * fpw(q[i].y) % P;
		change(1, 1, n - 1, q[i].l, q[i].s);
		ll t1 = (M[1][0][0] + M[1][0][1]) * (1 + P - poi[1].p) % P;
		ll t2 = (M[1][1][0] + M[1][1][1]) * poi[1].p % P;
		ll nw = (t1 + t2) % P;
		ans = (ans + v * (pre - nw + P)) % P, pre = nw;
	}
	write((ans % P + P) % P);
	return 0;
}