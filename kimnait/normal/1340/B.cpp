#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = 998244353;
const int N = (int)2e3 + 7;
const long double PI = acos(-1);
char s[2007][17];
string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool dp[N][N];
int dp2[N][N];
char ans[N];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i]);
	}
	dp[n+1][0] = true;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 10; j++) {
			int cnt = 0;
			bool gg = false;
			for (int k = 0; k < 7; k++) {
				if (num[j][k] == '1' && s[i][k] == '0') cnt++;
				if (num[j][k] == '0' && s[i][k] == '1') gg = true;
			}
			if (gg) continue ;
			for (int k = 0; k + cnt <= m; k++) {
				if (dp[i+1][k]) {
					dp[i][k+cnt] = true;
					dp2[i][k+cnt] = j;
				}
			}
		}
	}
	if (dp[1][m] == false) { puts("-1"); return 0; }
	int cur = m;
	for (int i = 1; i <= n; i++) {
		ans[i] = dp2[i][cur] + '0';
		int cnt = 0;
		for (int k = 0; k < 7; k++) {
			if (s[i][k] == '0' && num[ dp2[i][cur] ][k] == '1') cnt++;
		}
		cur -= cnt;
	}
	printf("%s\n", ans + 1);
	return 0;
}