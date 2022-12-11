#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT)
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1024;
char a0[N], a[N], b0[N][N], b[N][N];
int c[16], n, len, la, p0;
bool ban[N][N];
void init(char *s0, char *s, bool *ban) {
	int x = strlen(s0 + 1), p = len - x + 1;
	rep(i, 1, p - 1) s[i] = 0, ban == NULL ? 0 : ban[i] = i < p0;
	rep(i, 1, x) s[p++] = s0[i] == '?' ? -1 : s0[i] & 15;
}
int rk[N][N], kth[N][N], dp[N][N];
int main() {
	scanf("%s%d", a0 + 1, &n); len = la = strlen(a0 + 1);
	rep(i, 1, n) {
		scanf("%s", b0[i] + 1);
		len = max(len, (int)strlen(b0[i] + 1));
	}
	++len;
	p0 = len - la + 1;
	rep(i, 0, 9) scanf("%d", c + i);
	init(a0, a, NULL);
	rep(i, 1, n) init(b0[i], b[i], ban[i]);
	rep(i, 1, n) rk[len + 1][i] = kth[len + 1][i] = i;
	per(t, len + 1, 0) rep(i, 0, n + 1) dp[t][i] = -1;
	dp[len + 1][n + 1] = 0;
	per(t, len, 1) {
		static int ord[N];
		rep(i, 1, n) ord[i] = i;
		sort(ord + 1, ord + n + 1, [&](int x, int y) {
			return b[x][t] == b[y][t] ? rk[t + 1][x] < rk[t + 1][y] : b[x][t] < b[y][t];
		});
		rep(i, 1, n) rk[t][ord[i]] = i, kth[t][i] = ord[i];
		per(num, 9, 0) {
			if(t == p0 && !num) continue ;
			if(~a[t] && a[t] != num) continue ;
			int id = n + 1;
			rep(i, 1, n) if(b[i][t] >= 10 - num) id = min(id, rk[t][i]);
			int w = 0;
			rep(i, 1, n) w += !num && ban[i][t] ? 0 : c[(b[i][t] + num) % 10];
			per(i, n + 1, 1) {
				if(i <= n) {
					int u = kth[t + 1][i];
					if(b[u][t] >= 9 - num) id = min(id, rk[t][u]);
					w += c[(b[u][t] + num + 1) % 10] - (!num && ban[u][t] ? 0 : c[(b[u][t] + num) % 10]);
				}
				if(~dp[t + 1][i])
					dp[t][id] = max(dp[t][id], dp[t + 1][i] + w);
			}
		}
	}
	printf("%d\n", dp[1][n + 1]);
	return 0;
}