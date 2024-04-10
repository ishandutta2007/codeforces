#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

#ifndef DEBUG
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)
#endif

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int n, p[16];
ll k;

void dfs(int i, int R, ll nw, vector <ll> &lst) {
	if (i == R) {lst.PB(nw); return;}
	dfs(i + 1, R, nw, lst);
	while (nw <= LINF / p[i]) {
		nw *= p[i];
		dfs(i + 1, R, nw, lst);
	}
}

vector <ll> A, B;

ll solve(ll lim) {
	int j = B.size() - 1;
	ll ans = 0;
	rep(i, A.size()) if (A[i] <= lim) {
		while (j && A[i] > lim / B[j]) -- j;
		ans += j + 1;
	}
//	printf("%lld\n", ans);
	return ans;
}

int main() {
	n = read();
	rep(i, n) p[i] = read();
	k = read();
	mt19937 rng((ull)(new char));
	shuffle(p, p + n, rng);
	dfs(0, n / 2, 1, A);
	dfs(n / 2, n, 1, B);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
//	rep(i, A.size()) printf("%lld ", A[i]); puts("");
//	rep(i, B.size()) printf("%lld ", B[i]); puts("");
	ll lb = 1, rb = 1e18;
	while (lb < rb) {
		ll md = (lb + rb) >> 1;
//		printf("%lld %lld %lld ", lb, rb, md);
		if (solve(md) < k) lb = md + 1;
		else rb = md;
	}
	printf("%lld\n", lb);
	return 0;
}