#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 100005, mod = 998244353;
ll pq[maxn][2], ipq[maxn][2];
ll seg[maxn << 2][2][2];

inline ll power(ll x, int k) {
	if(k < 0) k += mod - 1;
	ll res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

void update(int now, int M) {
	memset(seg[now], 0, sizeof seg[now]);
	for(int S = 0; S < 8; S ++) {
		int a = S & 1, b = S >> 1 & 1, c = S >> 2 & 1;
		(seg[now][a][c] += seg[now << 1][a][b] *
		 seg[now << 1 | 1][b][c] % mod * ipq[M + 1][b]) %= mod;
	}
}

void erase(int now, int L, int R, int p, int s1, int s2) {
	if(L == R) {
		(seg[now][s1][s2] -= pq[p][s1] * pq[p + 1][s2]) %= mod;
		if(seg[now][s1][s2] < 0) seg[now][s1][s2] += mod;
	}
	else {
		int M = (L + R) >> 1;
		if(p <= M) erase(now << 1, L, M, p, s1, s2);
		else erase(now << 1 | 1, M + 1, R, p, s1, s2);
		update(now, M);
	}
	/* debug("%d-%d: <<%lld <>%lld ><%lld >>%lld\n", */
	/* 		L, R + 1, seg[now][0][0], seg[now][0][1], seg[now][1][0], seg[now][1][1]); */
}

void build(int now, int L, int R) {
	if(L == R)
		for(int S = 0; S < 4; S ++) {
			int a = S & 1, b = S >> 1 & 1;
			seg[now][a][b] = pq[L][a] * pq[R + 1][b] % mod;
		}
	else {
		int M = (L + R) >> 1;
		build(now << 1, L, M);
		build(now << 1 | 1, M + 1, R);
		update(now, M);
	}
	/* debug("%d-%d: <<%lld <>%lld ><%lld >>%lld\n", */
	/* 		L, R + 1, seg[now][0][0], seg[now][0][1], seg[now][1][0], seg[now][1][1]); */
}

struct collision {
	int ta, tb, id, a, b;
};
collision co[maxn << 1];
int pipx[maxn], pipv[maxn];

int main() {
	int n = read;
	if(n == 1) return puts("0"), 0;

	ll inv100 = power(100, -1);
	for(int i = 1; i <= n; i ++) {
		read(pipx[i], pipv[i]);
		int p = read;
		pq[i][1] = p * inv100 % mod;
		pq[i][0] = (100 - p) * inv100 % mod;
		ipq[i][1] = power(pq[i][1], -1);
		ipq[i][0] = power(pq[i][0], -1);
	}

	int cp = 0;
	for(int i = 1; i < n; i ++) {
		co[++ cp] = {pipx[i + 1] - pipx[i], pipv[i] + pipv[i + 1], i, 1, 0};
		if(pipv[i] > pipv[i + 1])
			co[++ cp] = {pipx[i + 1] - pipx[i], pipv[i] - pipv[i + 1], i, 1, 1};
		if(pipv[i + 1] > pipv[i])
			co[++ cp] = {pipx[i + 1] - pipx[i], pipv[i + 1] - pipv[i], i, 0, 0};
	}

	std::sort(co + 1, co + cp + 1, [](collision a, collision b) {
				return 1ll * a.ta * b.tb < 1ll * b.ta * a.tb;
			});

	build(1, 1, n - 1);
	ll ans = 0, las = 1;
	for(int i = 1; i <= cp; i ++) {
		erase(1, 1, n - 1, co[i].id, co[i].a, co[i].b);
		ll p = (seg[1][0][0] + seg[1][0][1] + seg[1][1][0] + seg[1][1][1]) % mod;
		/* debug("%lld\n", p); */
		(ans += (las - p + mod) * co[i].ta % mod * power(co[i].tb, -1)) %= mod;
		las = p;
	}

	printf("%lld\n", ans);
}