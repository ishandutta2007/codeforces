#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 998244353;
const int g = 3;

struct Mat {
	int n, m;
	int a[105][105];

	Mat() { memset(a, 0, sizeof(a)); }

	Mat operator * (const Mat &oth) const {
		Mat ans;
		ans.n = n; ans.m = oth.m;
		rep(i, ans.n) rep(j, ans.m) rep(k, m)
			(ans.a[i][j] += (ll)a[i][k] * oth.a[k][j] % (mod - 1)) %= mod - 1;
		return ans;
	}
};

Mat pow(Mat x, int n) {
	Mat ans;
	ans.n = x.n; ans.m = x.m;
	rep(i, ans.n) ans.a[i][i] = 1;
	for (; n; n >>= 1, x = x * x)
		if (n & 1) ans = ans * x;
	return ans;
}

int pow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = (ll)x * x % mod)
		if (n & 1) ans = (ll)ans * x % mod;
	return ans;
}

const int M = 32768;
unordered_map <int, int> REM;

void init_dlog() {
	int x = 1;
	rep(i, M) x = (ll)x * g % mod;
	int y = 1;
	rep(i, M) {
		if (!REM.count(y)) REM[y] = i * M;
		y = (ll)y * x % mod;
	}
}

int dlog(int x) {
	int y = x;
	rep(i, M) {
		if (REM.count(y))
			return ((REM[y] - i) % (mod - 1) + (mod - 1)) % (mod - 1);
		y = (ll)y * g % mod;
	}
	return -1;
}

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int exgcd(int a, int b, int &x, int &y) {
	if (!b) { x = 1; y = 0; return a; }
	else {
		int d = exgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return d;
	}
}

int inv(int x, int mod) {
	int a, b;
	int d = exgcd(x, mod, a, b);
	assert(d == 1);
	return (a % mod + mod) % mod;
}

int k;
int b[105];
int n, m;

int main() {
	scanf("%d", &k);
	rep(i, k) scanf("%d", &b[i]), b[i] %= mod - 1;
	scanf("%d %d", &n, &m);
	init_dlog();
	int logm = dlog(m);
	Mat trans;
	trans.n = k; trans.m = k;
	rep(i, k) trans.a[0][i] = b[i];
	rep(i, k - 1) trans.a[i + 1][i] = 1;
	trans = pow(trans, n - k);
	Mat ini;
	ini.n = k; ini.m = 1;
	ini.a[0][0] = 1;
	trans = trans * ini;
	int c = trans.a[0][0];
	int gc = gcd(c, mod - 1);
	if (logm % gc != 0) { puts("-1"); return 0; }
	int x = (ll)inv(c / gc, (mod - 1) / gc) * (logm / gc) % (mod - 1);
	printf("%d\n", pow(g, x));
	return 0;
}