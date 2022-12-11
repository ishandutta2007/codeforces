#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 100500;
ll n, m, K, P;
ll s[N];
struct Mat {
	int n, m;
	ll f[3][3];
	Mat() {}
	Mat(int n, int m) : n(n), m(m) { memset(f, 0, sizeof(f)); }
	
	inline void add(ll &x, ll y) {
		x += y; if (x >= P) x %= P;
	}
	
	Mat operator * (Mat b) {
		Mat t(n, b.m);
		for (int i = 1;i <= n; i++) 
			for (int j = 1;j <= b.m; j++) 
				for (int k = 1;k <= m; k++)
					add(t.f[i][j], f[i][k] * b.f[k][j]);
		return t;
	}
}a[N], b[N], F, I;

struct Q {
	int f; ll x, y;
	bool operator < (const Q &b) const {
		return x < b.x;
	}
}q[N];

Mat fpw(Mat x, ll mi) {
	Mat res = I;
	while (mi) {
		if (mi & 1) res = res * x;
		x = x * x; mi >>= 1;
	}
	return res;
}

struct SegmentTree {
	int l, r; Mat mt;
	#define l(x) t[x].l
	#define r(x) t[x].r
	#define mt(x) t[x].mt
}t[N<<2];

#define ls p << 1
#define rs p << 1 | 1

void build(int l, int r, int p) {
	l(p) = l, r(p) = r;
	if (l == r) return mt(p) = a[l], void();
	int mid = (l + r) >> 1;
	build(l, mid, ls), build(mid + 1, r, rs);
	mt(p) = mt(ls) * mt(rs);
}

void change(int p, int x, Mat tmp) {
	if (l(p) == r(p)) return mt(p) = tmp, void();
	if (r(ls) >= x) change(ls, x, tmp);
	else change(rs, x, tmp);
	mt(p) = mt(ls) * mt(rs);
}

int main() {
	I = Mat(2, 2), I.f[1][1] = I.f[2][2] = 1;
	F = Mat(1, 2), F.f[1][2] = 1;
	read(K), read(P), read(n);
	for (int i = 0;i < n; i++) read(s[i]), s[i] %= P;
	for (int i = 1;i <= n; i++) {
		a[i] = Mat(2, 2); 
		a[i].f[2][1] = 1, a[i].f[1][2] = s[i-1];
		a[i].f[2][2] = s[i == n ? 0 : i]; b[i] = a[i];
	} build(1, n, 1), read(m);
	for (int i = 1;i <= m; i++) 
		read(q[i].x), read(q[i].y), q[i].f = 2,
		q[i].y %= P, q[i+m] = q[i], q[i+m].x++, q[i+m].f--;
	m <<= 1, sort(q + 1, q + m + 1);
	ll pre = 0, now = 0, st, ed;
	while (m && q[m].x > K) m--;
	for (ed = st = 1;st <= m; st = ++ed) {
		now = (q[st].x - 1) / n, F = F * fpw(mt(1), now - pre);
		while (ed < m && (q[ed+1].x - 1) / n == now) ed++;
		for (int i = st;i <= ed; i++) {
			int k = (q[i].x - 1) % n + 1;
			b[k].f[q[i].f][2] = q[i].y, change(1, k, b[k]); 
		}  pre = now; if (now == (K / n)) break;
		F = F * mt(1), pre = now + 1;
		for (int i = st;i <= ed; i++) {
			int k = (q[i].x - 1) % n + 1;
			change(1, k, b[k] = a[k]);
		}
	}
	
	F = F * fpw(mt(1), (K / n) - pre), K %= n;
	for (int i = 1;i <= K; i++) F = F * b[i];
	printf ("%lld\n", F.f[1][1]);
	
	return 0;
}