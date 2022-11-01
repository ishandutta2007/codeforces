#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

inline void addmax(int &x, int y) { x = max(x, y); }

int f[6][N], s[N], a[N];
int T, n, k, z, ans;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &k, &z);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= z; j++) f[j][i] = -1;
		}
		f[0][1] = a[1]; ans = 0;
		for (int i = 0; i <= z; i++) {
			int maxn = -0x7fffffff;
			for (int j = 1; j <= n; j++) {
				if (j - 1 + i * 2 > k) break;
				if (f[i][j] != -1) addmax(maxn, f[i][j] - s[j]);
				if (maxn != -0x7fffffff) addmax(f[i][j], maxn + s[j]);
				addmax(ans, f[i][j]);
			}
			for (int j = 1; j <= n; j++) {
				if (f[i][j] == -1) continue;
				for (int k = i + 1; k <= z; k++) {
					int go = k - i, now = j - 1 + i * 2;
					if (now + go <= ::k && j - go >= 1) addmax(f[k][j - go], f[i][j] + s[j - 1] - s[j - go - 1]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}