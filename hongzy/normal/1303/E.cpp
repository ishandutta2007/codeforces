#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 400 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
char s[N], t[N];
int n, m, dp[N][N];
int main() {
	int T; scanf("%d", &T);
	while(T --) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1); m = strlen(t + 1);
		bool tag = 0;
		for(int l = 0; l <= m; l ++) {
			for(int i = 0; i <= n + 1; i ++)
				fill(dp[i], dp[i] + m + 2, -233);
			dp[0][0] = l;
			for(int i = 1; i <= n; i ++) {
				for(int j = 0; j <= l; j ++) if(-233 != dp[i - 1][j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					if(j != l && t[j + 1] == s[i]) dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
					if(dp[i - 1][j] != m && t[ dp[i - 1][j] + 1 ] == s[i])
						dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
				}
			}
			if(dp[n][l] >= m) {
				tag = 1; break ;
			}
		}
		puts(tag ? "YES" : "NO");
	}
	return 0;
}