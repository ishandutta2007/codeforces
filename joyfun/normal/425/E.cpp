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
const int mod = 1000000007;
int n, K, mi[N * N], dp[N][N];

void pp(int &x, int y) {
	x += y;
	if (x >= mod) x-= mod;
}

int main() {
	scanf("%d%d", &n, &K);
	mi[0] = 1;
	for (int i = 1; i < N * N; i++) mi[i] = mi[i - 1] * 2 % mod;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			for (int k = j - 1; k < i; k++) {
				pp(dp[i][j], 1ll * dp[k][j - 1] * (mi[i - k] - 1 + mod) % mod * mi[(i - k) * k] % mod);
			}
		}
	}
	printf("%d\n", dp[n][K]);
	return 0;
}