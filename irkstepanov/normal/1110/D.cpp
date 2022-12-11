#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int nmax = 1e6 + 10;
const int k = 7;

int cnt[nmax];

int dp[k][k];
int nx[k][k];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 1; i <= m; ++i) {
		memset(nx, -1, sizeof(nx));
		for (int a = 0; a < k; ++a) {
			for (int b = 0; b < k; ++b) {
				if (dp[a][b] == -1) {
					continue;
				}
				for (int z = 0; z <= a && z <= b && z <= cnt[i]; ++z) {
					for (int r = (cnt[i] - z) % 3; r < k && r <= cnt[i] - z; r += 3) {
						int val = dp[a][b] + z + (cnt[i] - z - r) / 3;
						nx[b - z][r] = max(nx[b - z][r], val);
					}
				}
			}
		}
		memcpy(dp, nx, sizeof(nx));
	}

	int ans = 0;
	for (int a = 0; a < k; ++a) {
		for (int b = 0; b < k; ++b) {
			ans = max(ans, dp[a][b]);
		}
	}
	cout << ans << "\n";

}