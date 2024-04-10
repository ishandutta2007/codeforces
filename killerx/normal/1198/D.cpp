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
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)
 
inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
char s[55][55];
int dp[55][55][55][55];
int sum[55][55];

int cnt(int x0, int x1, int y0, int y1) {
	return sum[x1][y1] - sum[x0][y1] - sum[x1][y0] + sum[x0][y0];
}

int DP(int x0, int x1, int y0, int y1) {
	// eprintf("%d %d %d %d\n", x0, x1, y0, y1);
	int & res = dp[x0][x1][y0][y1];
	if (cnt(x0, x1, y0, y1) == 0) return 0;
	if (~res) return res;
	res = max(x1 - x0, y1 - y0);
	for (int x = x0 + 1; x < x1; ++ x) res = min(res, DP(x0, x, y0, y1) + DP(x, x1, y0, y1));
	for (int y = y0 + 1; y < y1; ++ y) res = min(res, DP(x0, x1, y0, y) + DP(x0, x1, y, y1));
	return res;
}

int main() {
	n = read();
	rep(i, n) scanf("%s", s[i]);
	rep(i, n) rep(j, n) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (s[i][j] == '#');
	memset(dp, -1, sizeof dp);
	printf("%d\n", DP(0, n, 0, n));
	return 0;
}