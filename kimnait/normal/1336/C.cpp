#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
//#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int N = (int)3e3 + 7;
const int mod = 998244353;
char s1[ N ], s2[ N ];
int dp[N][N];
int sum(int v1, int v2) {
	v1 += v2;
	if (v1 >= mod) v1 -= mod;
	return v1;
}
void add(int i, int j, int ii, int jj, int p) {
	dp[ii][jj] = sum(dp[i][j], dp[ii][jj]);
}
int main() {
	scanf("%s %s", s1 + 1, s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	dp[0][0] = 1;
	for (int i = n; i >= 1; i--) {
		int pre = n - i;
		for (int j = pre; j >= 0; j--) {
			if (j+1 > m ||s1[i] == s2[j+1]) {
				int k = pre - j;
				add(j, k, j+1, k, i);
			}
		}

		for (int j = pre; j >= 0; j--) {
			int k = pre - j;
			if (k >= n - m) {
				if (s1[i] == s2[m-(k-(n-m))])
					add(j, k, j, k+1, i);
			} else {
				add(j, k, j, k+1, i);
			}
		}
		if (i > m) {
			dp[0][n-i+1] = n - i + 2;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = sum(ans, dp[i][n-i]);
	}
	printf("%d\n", ans);
	return 0;
}