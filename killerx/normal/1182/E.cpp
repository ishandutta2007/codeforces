#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typedef(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

typedef vector <vi> mat;

mat operator * (const mat & x, const mat & y) {
	mat z(x.size(), vi(y[0].size()));
	rep(i, x.size()) rep(j, y[0].size()) rep(k, y.size()) {
		int v = 1LL * x[i][k] * y[k][j] % (mod - 1);
		if (v < 0) v += mod - 1;
		z[i][j] += v;
		if (z[i][j] >= mod - 1) z[i][j] -= mod - 1;
	}
	return z;
}

mat mul1 = {
	{2, 0, 0, -1, 1},
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1}
};

mat mul2 = {
	{1, 1, 1},
	{1, 0, 0},
	{0, 1, 0}
};

mat ori1 = {
	{2},
	{0},
	{0},
	{0},
	{2}
};

mat ori2 = {
	{0},
	{0},
	{1}
};

mat ori3 = {
	{0},
	{1},
	{0}
};

mat ori4 = {
	{1},
	{0},
	{0}
};

mat qp(mat x, ll n) {
	mat ans(x.size(), vi(x[0].size()));
	rep(i, x.size()) ans[i][i] = 1;
	while (n) {
		if (n & 1) ans = ans * x;
		x = x * x;
		n >>= 1;
	}
	return ans;
}

int qp(int x, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = 1LL * ans * x % mod;
		x = 1LL * x * x % mod;
		n >>= 1;
	}
	return ans;
}

int main() {
	ll n;
	int f1, f2, f3, c;
	scanf("%lld%d%d%d%d", &n, &f1, &f2, &f3, &c);
	int ans1 = (qp(mul2, n - 3) * ori2)[0][0];
	int ans2 = (qp(mul2, n - 3) * ori3)[0][0];
	int ans3 = (qp(mul2, n - 3) * ori4)[0][0];
	int ansc = (qp(mul1, n - 4) * ori1)[0][0];
//	cerr << ans1 << " " << ans2 << " " << ans3 << " " << ansc << endl;
	printf("%lld\n", 1LL * qp(f1, ans1) * qp(f2, ans2) % mod * qp(f3, ans3) % mod * qp(c, ansc) % mod);
	return 0;
}