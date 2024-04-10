#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN 123456
#define maxM 255

int n, m;
int go[maxN][30], len[5], dp[maxM][maxM][maxM];
char s[maxN], t1[maxM], t2[maxM], p[5][maxM];
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 0; i < 26; i++)
		go[n][i] = go[n + 1][i] = n + 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++)
			go[i][j] = go[i + 1][j];
		go[i][s[i + 1] - 'a'] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		int id;
		scanf("%s%d", t1, &id);
		if (t1[0] == '-') {
			--len[id];
		} else {
			++len[id];
			scanf("%s", t2);
			p[id][len[id]] = t2[0];
			for (int p1 = id == 1 ? len[1] : 0; p1 <= len[1]; p1++)
				for (int p2 = id == 2 ? len[2] : 0; p2 <= len[2]; p2++)
					for (int p3 = id == 3 ? len[3] : 0; p3 <= len[3]; p3++)
						dp[p1][p2][p3] = n + 1;
			for (int p1 = id == 1 ? len[1] : 0; p1 <= len[1]; p1++)
				for (int p2 = id == 2 ? len[2] : 0; p2 <= len[2]; p2++)
					for (int p3 = id == 3 ? len[3] : 0; p3 <= len[3]; p3++) {
						if (p1 > 0)
							dp[p1][p2][p3] = min(dp[p1][p2][p3], go[dp[p1 - 1][p2][p3]][p[1][p1] - 'a']);
						if (p2 > 0)
							dp[p1][p2][p3] = min(dp[p1][p2][p3], go[dp[p1][p2 - 1][p3]][p[2][p2] - 'a']);
						if (p3 > 0)
							dp[p1][p2][p3] = min(dp[p1][p2][p3], go[dp[p1][p2][p3 - 1]][p[3][p3] - 'a']);
					}
		}
		puts(dp[len[1]][len[2]][len[3]] <= n ? "YES" : "NO");
	}
}