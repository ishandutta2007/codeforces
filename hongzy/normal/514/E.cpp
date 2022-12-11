#include <algorithm>
#include <cstdio>
using namespace std;

const int mo = 1e9 + 7;
const int N = 103;

struct mat {
	int n, m, a[N][N];
} st, tr;

mat operator * (const mat &a, const mat &b) {
	static mat tans;
	tans.n = a.n; tans.m = b.m;
	for(int i = 1; i <= tans.n; i ++) {
		for(int j = 1; j <= tans.m; j ++) {
			tans.a[i][j] = 0;
			for(int k = 1; k <= a.m; k ++) {
				(tans.a[i][j] += 1ll * a.a[i][k] * b.a[k][j] % mo) %= mo;
			}
		}
	}
	return tans;
}

mat mpow(mat &a, int b) {
	static mat tans, ta;
	tans = a; ta = a; b --;
	for(; b >= 1; b >>= 1, ta = ta * ta)
		if(b & 1) tans = tans * ta;
	return tans;
}

int n, d, cnt[N], dp[N];
int main() {
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x); cnt[x] ++;
	}
	dp[0] = 1;
	for(int i = 1; i <= 100; i ++) {
		for(int j = 1; j <= i; j ++) {
			(dp[i] += dp[i - j] * 1ll * cnt[j] % mo) %= mo;
		}
	}
	if(d <= 100) {
		int res = dp[0];
		for(int i = 1; i <= d; ++ i) {
			(res += dp[i]) %= mo;
		}
		printf("%d\n", res);
		return 0;
	}
	st.n = 1; st.m = 101; st.a[1][101] = 1;
	for(int i = 1; i <= 100; i ++) {
		st.a[1][i] = dp[i];
		(st.a[1][101] += dp[i]) %= mo;
	}
	tr.n = tr.m = 101;
	for(int i = 1; i <= 101; i ++) {
		fill(tr.a[i] + 1, tr.a[i] + 101 + 1, 0);
	}
	for(int i = 1; i < 100; i ++) {
		tr.a[i + 1][i] = 1;
	}
	for(int i = 1; i <= 100; i ++) {
		tr.a[i][100] = tr.a[i][101] = cnt[100 - i + 1];
	}
	tr.a[101][101] = 1;
	st = st * mpow(tr, d - 100);
	printf("%d\n", st.a[1][101]);
	return 0;
}
/*
dp[i] = \sum_{j = 1}^{100} cnt[j] * dp[i - j]

*/