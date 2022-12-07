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

const int N = 80;
const int inf = 0x3f3f3f3f;
int n;
char s[N];
vi a[3];
vi cnt[3][3];

void pp(int &x, int y) {
	x = min(x, y);
}

int dp[N][N][N][3];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'V') a[0].pb(i);
		else if (s[i] == 'K') a[1].pb(i);
		else a[2].pb(i);
	}
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			for (int i = 0; i < sz(a[x]); i++) {
				if (x == y) continue;
				cnt[x][y].pb(0);
				for (int j = 0; j < sz(a[y]); j++) 
					if (a[y][j] < a[x][i]) cnt[x][y][i]++;
			}
		}
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sz(a[0]); j++)
			for (int k = 0; k <= sz(a[1]); k++)
				for (int l = 0; l < 3; l++)
					dp[i][j][k][l] = inf;
	dp[0][0][0][2] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sz(a[0]); j++) {
			for (int k = 0; k <= sz(a[1]); k++) {
				for (int l = 0; l < 3; l++) {
					if (dp[i][j][k][l] == inf) continue;
					int x = i - j - k;
					//	printf("%d %d %d %d %d\n", i, j, k, l, dp[i][j][k][l]);
					if (j < sz(a[0])) {
						int v = max(0, k - cnt[0][1][j]) + max(0, x - cnt[0][2][j]);
						pp(dp[i + 1][j + 1][k][0], dp[i][j][k][l] + abs(a[0][j] + v - (i + 1)));
					}
					if (l != 0 && k < sz(a[1])) {
						int v = max(0, j - cnt[1][0][k]) + max(0, x - cnt[1][2][k]);
						pp(dp[i + 1][j][k + 1][1], dp[i][j][k][l] + abs(a[1][k] + v - (i + 1)));
					}
					if (x < sz(a[2])) {
						int v = max(0, j - cnt[2][0][x]) + max(0, k - cnt[2][1][x]);
						pp(dp[i + 1][j][k][2], dp[i][j][k][l] + abs(a[2][x] + v - (i + 1)));
					}
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < 3; i++) pp(ans, dp[n][sz(a[0])][sz(a[1])][i]);
	printf("%d\n", ans);
	return 0;
}