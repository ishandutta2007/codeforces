/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
   __  __                  __   __
  |  |/  |.-----.--.--.--.|  |_|  |--.
  |     < |  -__|  |  |  ||   _|     |
  |__|\__||_____|________||____|__|__|

 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 200005, mod = 998244353;
char s[maxn];
ll f[maxn][1 << 6];

inline void fuck (int i, int na, int nb, int nc, int xy, int yz, int xz, ll X) {
	(f[i][(na << 0) | (nb << 1) | (nc << 2) | (xy << 3) | (yz << 4) | (xz << 5)] += X) %= mod;
}

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));
	f[0][63] = 1;
	for (int i = 0; i < n; i ++) {
		int si = s[i + 1] - '0';
		for (int S = 0; S < 64; S ++)
			if (f[i][S]) {
				int na = S >> 0 & 1, nb = S >> 1 & 1, nc = S >> 2 & 1;
				int xy = S >> 3 & 1, yz = S >> 4 & 1, xz = S >> 5 & 1;
				for (int T = 0; T < 8; T ++) {
					int a = T >> 0 & 1, b = T >> 1 & 1, c = T >> 2 & 1;
					int x = a ^ b, y = b ^ c, z = a ^ c;
					if (na and a > si) continue;
					if (nb and b > si) continue;
					if (nc and c > si) continue;
					fuck(i + 1, na && (a == si), nb && (b == si), nc && (c == si),
							xy && (x + y == z), yz && (y + z == x),
							xz && (x + z == y), f[i][S]);
				}
		}
	}
	ll ans = 0;
	for (int S = 0; S < 64; S ++) {
		/* int na = S >> 0 & 1, nb = S >> 1 & 1, nc = S >> 2 & 1; */
		int xy = S >> 3 & 1, yz = S >> 4 & 1, xz = S >> 5 & 1;
		if (!xy and !yz and !xz)
			ans += f[n][S];
	}
	printf("%lld\n", ans % mod);
}