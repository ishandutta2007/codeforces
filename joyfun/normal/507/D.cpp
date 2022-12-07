#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define first fi
#define second se
#define sz(x) (int)x.size()
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

const int N = 1005;
int n, k, m;
int dp[N][105][2], f[N];

void pp(int &x, int y) {
	x += y;
	if (x >= m) x -= m;
}

int main() {

	scanf("%d%d%d", &n, &k, &m);
	for (int i = (n == 1); i <= 9; i++)
		pp(dp[1][i % k][i == 0], 1 % m);
	int s = 1;
	for (int i = 2; i <= n; i++) {
		s = 1ll * s * 10 % k;
		for (int j = 0; j < k; j++) {
			for (int f = 0; f < 2; f++) {
				for (int x = (i == n); x <= 9; x++) {
					if (j == 0 && !f) continue;
					pp(dp[i][(j + 1ll * s * x) % k][x == 0], dp[i - 1][j][f]);
				}
			}
		}
	}
	int ans = 0;
	f[0] = 1 % m;
	for (int i = 1; i <= n; i++) f[i] = 1ll * f[i - 1] * 10 % m;
	for (int i = 1; i < n; i++) pp(ans, 1ll * dp[i][0][0] * f[n - i - 1] % m * 9 % m);
	pp(ans, dp[n][0][0]);
	printf("%d\n", ans);
	return 0;
}