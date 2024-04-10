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

const int N = 105;
const int inf = 0x3f3f3f3f;
int n, m, k, g[N][N], p[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &g[i][j]);
	int ans = inf;
	if (n > k) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int k = 0; k < m; k++) p[i][k] = g[i][k];
			for (int j = i + 1; j < n; j++) {
				int c1 = 0, c2 = 0;
				for (int k = 0; k < m; k++) {
					p[j][k] = p[j - 1][k]^1;
					c1 += (p[j][k] != g[j][k]);
					p[j][k] = p[j - 1][k];
					c2 += (p[j][k] != g[j][k]);
				}
				sum += min(c1, c2);
			}
			for (int j = i - 1; j >= 0; j--) {
				int c1 = 0, c2 = 0;
				for (int k = 0; k < m; k++) {
					p[j][k] = p[j + 1][k]^1;
					c1 += (p[j][k] != g[j][k]);
					p[j][k] = p[j + 1][k];
					c2 += (p[j][k] != g[j][k]);
				}
				sum += min(c1, c2);
			}
			ans = min(ans, sum);
		}
	} else {
		for (int i = 0; i < (1<<n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				p[j][0] = i>>j&1;
				sum += (p[j][0] != g[j][0]);
			}
			for (int k = 1; k < m; k++) {
				int c1 = 0, c2 = 0;
				for (int j = 0; j < n; j++) {
					p[j][k] = p[j][k - 1]^1;
					c1 += (p[j][k] != g[j][k]);
					p[j][k] = p[j][k - 1];
					c2 += (p[j][k] != g[j][k]);
				}
				sum += min(c1, c2);
			}
			ans = min(ans, sum);
		}
	}
	if (ans > k) ans = -1;
	printf("%d\n", ans);
	return 0;
}