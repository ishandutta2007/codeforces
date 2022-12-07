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

const int N = 35;
const int inf = 0x3f3f3f3f;

int n, m, x, q;
char g[N][N], s[555555];
int vis[26], w[26];

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	scanf("%d", &q); scanf("%s", s + 1);
	for (int i = 0; i < 26; i++) w[i] = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 'S') {
				for (int x = 1; x <= n; x++) {
					for (int y = 1; y <= m; y++) {
						if (g[x][y] == 'S') continue;
						int dx = x - i, dy = y - j;
						int dd = dx * dx + dy * dy;
						w[g[x][y] - 'a'] = min(w[g[x][y] - 'a'], dd);
					}
				}
			} else vis[g[i][j] - 'a'] = 1;
		}
	}
	scanf("%d", &q); scanf("%s", s + 1);
	int ans = 0;
	for (int i = 1; i <= q; i++) if (s[i] >= 'A' && s[i] <= 'Z') {
		if (w[s[i] - 'A'] == inf) {
			printf("-1\n");
			return 0;
		}
		ans += (w[s[i] - 'A'] > x * x);
	} else if (vis[s[i] - 'a'] == 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}