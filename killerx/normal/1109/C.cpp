// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair <int, int>
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define PI acos(-1)
#define MOD 1000000007
#define MUL 19260817
#define EPS 1e-10
#define INF 1e9
#define LINF 1e18

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 1 << 18;

ll sum[N << 1], speed[N << 1], mn[N << 1], lazy[N << 1], mul[N << 1];
void init() {rep(i, N << 1) sum[i] =  speed[i] = mn[i] = mul[i] = 0, lazy[i] = -LINF;}
void pd(int i) {
	if (lazy[i] != -LINF) {
		speed[i << 1] = speed[i << 1 | 1] = lazy[i];
		sum[i << 1] = lazy[i] * mul[i << 1];
		sum[i << 1 | 1] = lazy[i] * mul[i << 1 | 1];
		mn[i << 1] = mn[i << 1 | 1] = min(0LL, sum[i << 1]);
		lazy[i << 1] = lazy[i << 1 | 1] = lazy[i];
		lazy[i] = -LINF;
	}
}
void upd(int a, int b, int i, int l, int r, int v) {
	if (l <= a && b <= r) {
		lazy[i] = v;
		speed[i] = lazy[i];
		sum[i] = lazy[i] * mul[i];
		mn[i] = min(0LL, sum[i]);
		return;
	}
	if (r <= a || b <= l) return;
	pd(i);
	int md = (a + b) >> 1;
	upd(a, md, i << 1, l, r, v);
	upd(md, b, i << 1 | 1, l, r, v);
	sum[i] = sum[i << 1] + sum[i << 1 | 1];
	mn[i] = min(mn[i << 1], sum[i << 1] + mn[i << 1 | 1]);
}
ll qry(int a, int b, int i, int l, int r) {
	if (l <= a && b <= r) return sum[i];
	if (r <= a || b <= l) return 0;
	pd(i);
	int md = (a + b) >> 1;
	ll L = qry(a, md, i << 1, l, r);
	ll R = qry(md, b, i << 1 | 1, l, r);
	return L + R;
}
struct Ans {
	ll sum, mn;
	Ans() {}
	Ans(ll a, ll b): sum(a), mn(b) {}
};
Ans qrymn(int a, int b, int i, int l, int r) {
	if (l <= a && b <= r) return Ans(sum[i], mn[i]);
	if (r <= a || b <= l) return Ans(0, 0);
	pd(i);
	int md = (a + b) >> 1;
	Ans L = qrymn(a, md, i << 1, l, r);
	Ans R = qrymn(md, b, i << 1 | 1, l, r);
	return Ans(L.sum + R.sum, min(L.mn, L.sum + R.mn));
}
ll qrys(int a, int b, int i, int x) {
	if (a + 1 == b) return speed[i];
	pd(i);
	int md = (a + b) >> 1;
	if (x < md) return qrys(a, md, i << 1, x);
	return qrys(md, b, i << 1 | 1, x);
}
struct P {
	int t, s;
	P() {}
	P(int a, int b): t(a), s(b) {}
	bool operator < (const P &x) const {return t < x.t;}
};

int vt[N], svt;
int qtp[N], qa[N], qb[N], qc[N];
set <P> events;

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int q = read();
	rep(i, q) {
		qtp[i] = read();
		if (qtp[i] == 1) {
			qa[i] = read();
			qb[i] = read();
			vt[svt ++] = qa[i];
		}
		if (qtp[i] == 2) {
			qa[i] = read();
		}
		if (qtp[i] == 3) {
			qa[i] = read();
			qb[i] = read();
			qc[i] = read();
			vt[svt ++] = qa[i];
			vt[svt ++] = qb[i];
		}
	}
	vt[svt ++] = 0;
	vt[svt ++] = 1e9;
	sort(vt, vt + svt);
	svt = unique(vt, vt + svt) - vt;
	init();
	rep(i, svt - 1) mul[i + N] = vt[i + 1] - vt[i];
	for (int i = N - 1; i; -- i) mul[i] = mul[i << 1] + mul[i << 1 | 1];
	rep(i, q) {
		if (qtp[i] == 1) {
			int t = lower_bound(vt, vt + svt, qa[i]) - vt;
			int s = qb[i];
			set <P> :: iterator it = events.lower_bound(P(t, -1e9));
			int nxt = svt - 1;
			if (it != events.end()) nxt = it -> t;
			events.insert(P(t, s));
			upd(0, N, 1, t, nxt, s);
		}
		if (qtp[i] == 2) {
			int t = lower_bound(vt, vt + svt, qa[i]) - vt;
			set <P> :: iterator it = events.lower_bound(P(t, -1e9));
			it = events.erase(it);
			int nxt = 1e9;
			if (it != events.end()) nxt = it -> t;
			int lst = 0;
			if (it != events.begin()) {-- it; lst = it -> t;}
			int s = qrys(0, N, 1, lst);
			upd(0, N, 1, t, nxt, s);
		}
		if (qtp[i] == 3) {
			int L = lower_bound(vt, vt + svt, qa[i]) - vt;
			int R = lower_bound(vt, vt + svt, qb[i]) - vt;
			int v = qc[i];
			set <P> :: iterator it = events.lower_bound(P(L, -1e9));
			ld ans = -1;
			if (!v) ans = qa[i];
			else if (it != events.end() && it -> t <= R) {
				L = it -> t;
				if (qrymn(0, N, 1, L, R).mn + v <= 0) {
					int lb = L, rb = R;
					while (lb < rb) {
						int md = lb + rb >> 1;
						if (qrymn(0, N, 1, L, md).mn + v <= 0) rb = md;
						else lb = md + 1;
					}
					-- lb;
					ll lft = v + qry(0, N, 1, L, lb);
					ll nws = qrys(0, N, 1, lb);
					ans = vt[lb] - 1.0 * lft / nws;
				}
			}
			printf("%.7f\n", ans);
		}
	}
	return 0;
}