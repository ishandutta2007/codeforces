#include <bits/stdc++.h>
using namespace std;

using ld = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

const int SZ = 1 << 16;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() ++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 1 << 20;
int n, m;
int cnt[N];
int dp[2][3][3];
void I(int p) {
	for (int i = 0; i < 3; ++ i) for (int j = 0; j < 3; ++ j) dp[p][i][j] = -INF;
}

int main() {
	n = read(), m = read() + 10;
	for (int i = 0; i < n; ++ i) cnt[read() + 5] ++;
	int p = 0, q = 1;
	I(p); I(q);
	dp[p][0][0] = 0;
	for (int i = 1; i <= m; ++ i) {
		for (int j = 0; j < 3; ++ j) {
			for (int k = 0; k < 3; ++ k) {
				for (int l = 0; l < 3; ++ l) {
					if (cnt[i] >= j + k + l) {
						int x = (cnt[i] - j - k - l) / 3;
						dp[q][k][l] = max(dp[q][k][l], dp[p][j][k] + l + x);
					}
				}
			}
		}
		swap(p, q);
		I(q);
	}
	printf("%d\n", dp[p][0][0]);
	return 0;
}