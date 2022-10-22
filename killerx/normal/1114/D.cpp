// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

using ld = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 5005;

int n;
int c[N];
int cc[N];
int dp[N][N];
void chk(int &x, int y) {if (y < x) x = y;}

int main() {
	n = read();
	for (int i = 0; i < n; ++ i) c[i] = read();
	int m = 0;
	for (int i = 0; i < n; ++ i) {
		if (!i || c[i] != c[i - 1]) {
			++ m;
			cc[m] = c[i];
		}
	}
	for (int i = 1; i <= m; ++ i) for (int j = 1; j <= m; ++ j) dp[i][j] = INF;
	for (int i = 1; i <= m; ++ i) dp[i][i] = 0;
	for (int l = 1; l < m; ++ l) for (int i = 1, j; (j = i + l - 1) <= m; ++ i) {
		if (i > 1) chk(dp[i - 1][j + (j < m && cc[j + 1] == cc[i - 1])], dp[i][j] + 1);
		if (j < m) chk(dp[i - (i > 1 && cc[i - 1] == cc[j + 1])][j + 1], dp[i][j] + 1);
	}
	printf("%d\n", dp[1][m]);
	return 0;
}