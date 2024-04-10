#include <bits/stdc++.h>
using namespace std;

const int N = 105;
struct AC {
	int nxt[N][26], fail[N], ed[N], tot;
	void ins(const char * s, int n, int val) {
		int u = 0;
		for (int i = 0; i < n; ++ i) {
			int & v = nxt[u][s[i] - 'a'];
			if (!v) v = ++ tot;
			u = v;
		}
		ed[u] = val;
	}
	void build() {
		queue <int> que;
		for (int i = 0; i < 26; ++ i) {
			if (nxt[0][i]) {
				fail[nxt[0][i]] = 0;
				que.push(nxt[0][i]);
			}
		}
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (int i = 0; i < 26; ++ i) {
				if (nxt[u][i]) {
					fail[nxt[u][i]] = nxt[fail[u]][i];
					que.push(nxt[u][i]);
				} else {
					nxt[u][i] = nxt[fail[u]][i];
				}
			}
		}
	}
	int cal(int u) {
		int ans = 0;
		while (u) {
			ans += ed[u];
			u = fail[u];
		}
		return ans;
	}
} ac;
int n;
char s[1005], c[55];
int dp[1005][N];
int main() {
	scanf("%s", s);
	n = strlen(s);
	scanf("%s", c); ac.ins(c, strlen(c), 1);
	scanf("%s", c); ac.ins(c, strlen(c), -1);
	ac.build();
	for (int i = 0; i <= n; ++ i) {
		for (int j = 0; j <= ac.tot; ++ j) {
			dp[i][j] = -0x3f3f3f3f;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j <= ac.tot; ++ j) {
			int st = s[i] == '*' ? 0 : s[i] - 'a';
			int ed = s[i] == '*' ? 25 : s[i] - 'a';
			for (int k = st; k <= ed; ++ k) {
				int nj = ac.nxt[j][k];
				dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + ac.cal(nj));
			}
		}
	}
	int ans = -0x3f3f3f3f;
	for (int i = 0; i <= ac.tot; ++ i) {
		ans = max(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}