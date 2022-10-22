#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 998244353;

int n, lim;
int x[5], y[5];

int dp[25][25][25][25][2][2];

inline void uadd(int &x, int y) {
	x += y - mod;
	x += (x >> 31) & mod;
}

int main() {
	scanf("%d %d", &n, &lim);
	rep(i, n) scanf("%d %d", &x[i], &y[i]);
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][1][1] = 1;
	rep(i, 30) {
		int c_lim = lim >> i & 1;
		static int ndp[25][25][25][25][2][2];
		memset(ndp, 0, sizeof(ndp));
		rep(A, 25) rep(B, 25) rep(C, 25) rep(D, 25) rep(fx, 2) rep(fy, 2) {
			int v;
			if (v = dp[A][B][C][D][fx][fy]) {
				rep(mask, 1 << n) {
					int nA = A, nB = B, nC = C, nD = D, nfx = fx, nfy = fy;
					rep(i, n) {
						int c = mask >> i & 1;
						if (x[i] < 0) nA += -x[i] * c;
						if (x[i] > 0) nB += +x[i] * c;
						if (y[i] < 0) nC += -y[i] * c;
						if (y[i] > 0) nD += +y[i] * c;
					}
					if ((nA & 1) != (nB & 1)) continue;
					if ((nC & 1) != (nD & 1)) continue;
					nfx = (nA & 1) != c_lim ? (nA & 1) < c_lim : nfx;
					nfy = (nC & 1) != c_lim ? (nC & 1) < c_lim : nfy;
					nA >>= 1, nB >>= 1, nC >>= 1, nD >>= 1;
					uadd(ndp[nA][nB][nC][nD][nfx][nfy], v);
				}
			}
		}
		memcpy(dp, ndp, sizeof(dp));
	}
	int ans = dp[0][0][0][0][1][1];
	uadd(ans, mod - 1);
	printf("%d\n", ans);
	return 0;
}