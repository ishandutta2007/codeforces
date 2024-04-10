#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 2000 + 50, K = 55, D = 998244353;
int l[N], r[N];
s64 dp[2][K * 2][N], C[N][N], fact[N], P[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
#else
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	for (int i = 0; i < N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % D;
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % D;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j) P[i][j] = C[i][j] * fact[j] % D;
	int n, k;
	cin >> n >> k;
	//a[i] \in [1,n+1]
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
		l[i] = max(r[i] - k, l[i - 1]);
		r[i] = min(r[i] + k + 1, n + 1);
		//[l[i],r[i]) \to [0,l[i]] - [0,r[i]]
		if (r[i] <= l[i]) {
			puts("0");
			exit(0);
		}
	}
	bool d = 0;
	dp[d][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		d ^= 1;
		memset(dp[d], 0, sizeof(dp[d]));
		for (int j = l[i - 1]; j <= l[i - 1] + 2 * k + 1; ++j)
			for (int k = 0; k < i; ++k) {
				s64 f0 = dp[d ^ 1][j - l[i - 1]][k];
				if (!f0) continue;
				auto trans = [&](int nj) {
					//cout << i - 1 << " " << j << " " << k << " " << f0 << " " << nj << endl;
					if (nj <= j) { //j remains
						//a[i]<=j or a[i] \in S_k
						(dp[d][j - l[i]][k] += f0 * (j + k)) %= D;
						//else
						(dp[d][j - l[i]][k + 1] += f0) %= D;
					} else { //j <- nj
						//a[i]<=j or a[i] \in S_k
						if (k >= nj - j)
							(dp[d][nj - l[i]][k - (nj - j)] += f0 * (j + k) % D * P[k][nj - j]) %= D;
						//else
						if (k + 1 >= nj - j)
							(dp[d][nj - l[i]][k + 1 - (nj - j)] += f0 * P[k + 1][nj - j]) %= D;
					}
				};
				trans(l[i]);
				f0 = -f0;
				trans(r[i]);
			}
	}
	s64 ans = 0;
	for (int j = l[n]; j <= l[n] + 2 * k + 1; ++j)
		for (int k = 0; k <= n + 1 - j; ++k) {
			(ans += dp[d][j - l[n]][k] * P[n + 1 - j][k]) %= D;
		}
	cout << (ans % D + D) % D << endl;
}