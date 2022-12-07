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

const int N = 505;
int n, m;
bitset<N> dp[65][2][N];

int main() {
	scanf("%d%d", &n, &m);
	int u, v, w;
	while (m--) {
		scanf("%d%d%d", &u, &v, &w);
		dp[0][w][u][v] = 1;
	}
	for (int i = 1; i < 60; i++) {
		for (int j = 0; j < 2; j++) {
			for (int x = 1; x <= n; x++) {
				bitset<N> tmp;
				for (int y = 1; y <= n; y++)
					if (dp[i - 1][j][x][y]) tmp |= dp[i - 1][j^1][y];
				for (int y = 1; y <= n; y++)
					if (tmp[y]) dp[i][j][x][y] = 1;
			}
		}
	}
	bitset<N> s;
	s[1] = 1;
	int f = 0;
	ll ans = 0;
	for (int i = 59; i >= 0; i--) {
		bitset<N> tmp;
		for (int j = 1; j <= n; j++)
			if (s[j]) tmp |= dp[i][f][j];
		if (tmp.count()) {
			ans += (1ll<<i);
			s = tmp;
			f ^= 1;
		}
	}
	if (ans > 1e18) ans = -1;
	printf("%lld\n", ans);
	return 0;
}