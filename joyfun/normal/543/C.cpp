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

const int N = 25;
const int inf = 0x3f3f3f3f;
int n, m, a[N][N], w[N][N][2];
char g[N][N];
int dp[1<<N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", g[i]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	for (int i = 0; i < (1<<n); i++) dp[i] = inf;
	int sb = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int s = 0, sum = 0, Max = 0;
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (g[j][i] == g[k][i]) {
					cnt++;
					s |= (1<<k);
					sum += a[k][i];
					Max = max(Max, a[k][i]);
				}
			}
			w[i][j][0] = s;
			w[i][j][1] = sum - Max;
		}
	}
	dp[sb] = 0;
	for (int i = 0; i < (1<<n); i++) {
		int f = 0;
		for (; f < n; f++) if (!(i>>f&1)) break;
		for (int j = 0; j < m; j++) {
			dp[i|(1<<f)] = min(dp[i|(1<<f)], dp[i] + a[f][j]);
			dp[i|w[j][f][0]] = min(dp[i|w[j][f][0]], dp[i] + w[j][f][1]);
		}
	}
	printf("%d\n", dp[(1<<n) - 1]);
	return 0;
}