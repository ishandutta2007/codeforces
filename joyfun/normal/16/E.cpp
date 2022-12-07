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

const int N = 20;
int n;
double a[N][N], dp[1<<N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
	dp[(1<<n) - 1] = 1.0;
	for (int i = (1<<n) - 1; i >= 1; i--) {
		int cnt = 0;
		for (int x = 0; x < n; x++)
			if (i>>x&1) cnt++;
		for (int x = 0; x < n; x++) {
			if (i>>x&1) {
				for (int y = x + 1; y < n; y++) {
					if (i>>y&1) {
						dp[i^(1<<x)] += dp[i] * a[y][x] / (cnt * (cnt - 1) / 2);
						dp[i^(1<<y)] += dp[i] * a[x][y] / (cnt * (cnt - 1) / 2);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) printf("%.12f ", dp[1<<i]); printf("\n");
	return 0;
}