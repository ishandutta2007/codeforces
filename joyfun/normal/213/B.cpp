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
const int N = 105;

int n;
int a[15], dp[15][N], C[N][N];

void pp(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int get(int n) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= n; j++) {
			for (int x = max(0, a[i]); j + x <= n; x++) {
				pp(dp[i + 1][j + x], 1ll * dp[i][j] * C[j + x][j] % mod);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) pp(ans, dp[10][i]);
	return ans;
}

int main() {
	for (int i = 0; i < N; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		a[i]--;
		pp(ans, get(n - 1));
		a[i]++;
	}
	printf("%d\n", ans);
	return 0;
}