#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep(i, n) for (int i = 0; i < n; ++ i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
const ld eps = 1e-9;
int read() {
	int x = 0, f = 1, c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f ^= 1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}
void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[10], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x - x / 10 * 10;
	for (; tp; putchar(48 + stk[-- tp]));
}
const int N = 1 << 11;
const int mod = 1e9 + 7;
int dp[N][N];
int main() {
	int n = read();
	memset(dp, -1, sizeof dp);
	dp[n + n][0] = 0;
	for (int i = n + n - 1; ~i; -- i) {
		for (int j = 0; j <= n + n; ++ j) {
			bool flag = 0;
			dp[i][j] = 0;
			if (j && ~dp[i + 1][j - 1]) dp[i][j] += dp[i + 1][j - 1], flag = 1;
			if (dp[i][j] >= mod) dp[i][j] -= mod;
			if (j < n + n && ~dp[i + 1][j + 1]) dp[i][j] += dp[i + 1][j + 1], flag = 1;
			if (i & 1) ++ dp[i][j];
			if (dp[i][j] >= mod) dp[i][j] -= mod;
			if (!flag) dp[i][j] = -1;
//			cerr << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	write(dp[0][0]);
	return 0;
}