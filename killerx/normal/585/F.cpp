#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SuffixAutomata {
	static const int mxn = 1005;
	static const int sigma = 10;

	int tot, lst, len[mxn << 1], go[mxn << 1][sigma], link[mxn << 1];

	void init() {
		tot = lst = 1;
	}

	void append(int c) {
		int p = lst, np = lst = ++ tot;
		len[np] = len[p] + 1;
		for (; p && !go[p][c]; p = link[p]) go[p][c] = np;
		if (!p) link[np] = 1;
		else {
			int q = go[p][c];
			if (len[q] == len[p] + 1) link[np] = q;
			else {
				int nq = ++ tot;
				len[nq] = len[p] + 1;
				memcpy(go[nq], go[q], sigma << 2);
				link[nq] = link[q]; link[q] = link[np] = nq;
				for (; go[p][c] == q; p = link[p]) go[p][c] = nq;
			}
		}
	}

	void append(int &u, int &l, int c) {
		while (u && !go[u][c]) u = link[u], l = len[u];
		if (!u) u = 1, l = 0; else u = go[u][c], ++ l;
	}
} sa;

const int mod = 1e9 + 7;

int n, d;
char s[1005];
char X[55], Y[55];
int ovo[55][2005][10][2];
int dp[55][55][2005][2][2];

inline void uadd(int &x, int y) {
	x += y - mod;
	x += (x >> 31) & mod;
}

int DP(char t[]) {
	memset(dp, 0, sizeof(dp));
	dp[0][0][1][0][0] = 1;
	rep(i, d) rep(l, d + 1)
		for (int j = 1; j <= sa.tot; ++ j) rep(fless, 2) rep(fsucc, 2) {
			if (!dp[i][l][j][fless][fsucc]) continue;
			for (int c = 0; c <= (fless ? 9 : t[i] - '0'); ++ c) {
				uadd(dp[i + 1]
					[ovo[l][j][c][0]]
					[ovo[l][j][c][1]]
					[fless || (c < t[i] - '0')]
					[fsucc || (ovo[l][j][c][0] >= d / 2)],
					dp[i][l][j][fless][fsucc]);
			}
		}
	int ans = 0;
	rep(l, d + 1) for (int j = 1; j <= sa.tot; ++ j) rep(fless, 2)
		uadd(ans, dp[d][l][j][fless][1]);
	return ans;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	scanf("%s", X);
	scanf("%s", Y);
	d = strlen(X);
	sa.init();
	rep(i, n) sa.append(s[i] - '0');
	rep(l, d + 1) for (int i = 1; i <= sa.tot; ++ i)
		rep(c, 10) {
			int ni = i, nl = l;
			sa.append(ni, nl, c);
			ovo[l][i][c][0] = nl;
			ovo[l][i][c][1] = ni;
		}
	int i = d - 1;
	while (X[i] == '0') X[i --] = '9';
	-- X[i];
	printf("%d\n", (DP(Y) + mod - DP(X)) % mod);
	return 0;
}