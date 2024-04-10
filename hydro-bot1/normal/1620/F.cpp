// Hydro submission #62c6d5b98672efa577c0237b@1657198009209
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 1, INF = 0x7f7f7f7f;
int n, a[N], dp[N][2][2], ans[N];
struct mdzz {int i, j, k;} las[N][2][2];
inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') w = -1; ch = getchar();}
	while (isdigit(ch)) {s = (s << 3) + (s << 1) + (ch ^ 48); ch = getchar();}
	return s * w;
}
inline void mian() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = INF;
	}
	dp[1][0][0] = dp[1][1][0] = -INF;
	for (int i = 2, x, y, z; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
			x = -a[i - 1], y = dp[i - 1][j][k];
			if (j) x = -x; if (k) swap(x, y);
			mdzz pl = (mdzz) {i - 1, j, k};
			for (int l = 0; l < 2; ++l) {
				z = (l ? 1 : -1) * a[i];
				if (z < y) continue;
				if (z < x) {if (dp[i][l][1] > x) dp[i][l][1] = x, las[i][l][1] = pl;}
				else {if (dp[i][l][0] > y) dp[i][l][0] = y, las[i][l][0] = pl;}
			}
		}
	}
	for (int l = 0; l < 2; ++l) for (int m = 0; m < 2; ++m) if (dp[n][l][m] < INF) {
		int i = n, j = l, k = m;
		mdzz pl;
		while (i >= 1) {
			ans[i] = j ? a[i] : -a[i];
			pl = las[i][j][k];
			i = pl.i; j = pl.j; k = pl.k;
		}
		printf("YES\n");
		for (i = 1; i <= n; ++i) printf("%d ", ans[i]);
		printf("\n");
		return ;
	}
	printf("NO\n");
}
int main() {
	int T = read();
	while (T--) mian();
	return 0;
}