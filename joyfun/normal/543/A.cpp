#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 505;
int n, m, b, mod, a[N];
int dp[N][N];

int main() {
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = a[i]; k <= b; k++) {
				dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= b; i++) ans = (ans + dp[m][i]) % mod;
	printf("%d\n", ans);
	return 0;
}