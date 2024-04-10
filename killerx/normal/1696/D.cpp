#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5, mxlg = 19;

inline void upd(int &x, int y) {
	x = std::min(x, y);
}

int n, a[mxn];
int dp[mxn];
int stk_mx[mxn], jmp_mx[mxn][mxlg], cost_mx[mxn][mxlg], top_mx;
int stk_mn[mxn], jmp_mn[mxn][mxlg], cost_mn[mxn][mxlg], top_mn;

inline void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) dp[i] = mxn;
	dp[0] = 0;
	top_mx = top_mn = 0;
	rep(i, n) {
		while (top_mx && a[stk_mx[top_mx - 1]] < a[i]) -- top_mx;
		while (top_mn && a[stk_mn[top_mn - 1]] > a[i]) -- top_mn;
		if (i) {
			int P0 = top_mx ? stk_mx[top_mx - 1] : -1;
			int P1 = top_mn ? stk_mn[top_mn - 1] : -1;
			int P = std::min(P0, P1);
			if (P0 > P) upd(dp[i], dp[P0] + 1);
			if (P1 > P) upd(dp[i], dp[P1] + 1);
			for (int k = mxlg - 1, x = P0; x > P && ~k; -- k) {
				if (jmp_mx[x][k] > P) {
					upd(dp[i], cost_mx[x][k] + 1);
					x = jmp_mx[x][k];
				}
			}
			for (int k = mxlg - 1, x = P1; x > P && ~k; -- k) {
				if (jmp_mn[x][k] > P) {
					upd(dp[i], cost_mn[x][k] + 1);
					x = jmp_mn[x][k];
				}
			}
		}
		jmp_mx[i][0] = top_mx ? stk_mx[top_mx - 1] : -1;
		cost_mx[i][0] = top_mx ? dp[stk_mx[top_mx - 1]] : -1;
		jmp_mn[i][0] = top_mn ? stk_mn[top_mn - 1] : -1;
		cost_mn[i][0] = top_mn ? dp[stk_mn[top_mn - 1]] : -1;
		rep(j, mxlg - 1) {
			jmp_mx[i][j + 1] = ~jmp_mx[i][j] ? jmp_mx[jmp_mx[i][j]][j] : -1;
			cost_mx[i][j + 1] = std::min(cost_mx[i][j], ~jmp_mx[i][j] ? cost_mx[jmp_mx[i][j]][j] : mxn);
			jmp_mn[i][j + 1] = ~jmp_mn[i][j] ? jmp_mn[jmp_mn[i][j]][j] : -1;
			cost_mn[i][j + 1] = std::min(cost_mn[i][j], ~jmp_mn[i][j] ? cost_mn[jmp_mn[i][j]][j] : mxn);
		}
		stk_mx[top_mx ++] = i;
		stk_mn[top_mn ++] = i;
	}
	printf("%d\n", dp[n - 1]);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}