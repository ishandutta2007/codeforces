#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
//#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int N = (int)1e5 + 7;
int aa[ N ], bb[ N ], cc[ N ];
int lb[ N*3 ][3], rb[ N*3 ][3];
PII a[ N*3 ];
inline long long val(int v1, int v2, int v3) {
	if (!v1 || !v2) return 4e18;
	return (v1 - v2)*1ll*(v1 - v2) + (v1 - v3)*1ll*(v1 - v3) + (v2 - v3)*1ll*(v2 - v3);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		int len = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", aa + i);
			a[++len] = MP(aa[i], 0);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", bb + i);
			a[++len] = MP(bb[i], 1);
		}
		for (int i = 1; i <= k; i++) {
			scanf("%d", cc + i);
			a[++len] = MP(cc[i], 2);
		}
		rb[len+1][0] = 0;
		rb[len+1][1] = 0;
		rb[len+1][2] = 0;
		sort(a + 1, a + len + 1);
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < 3; j++) {
				lb[i][j] = lb[i-1][j];
			}
			lb[i][ a[i].second ] = a[i].first;
		}
		for (int i = len; i >= 1; i--) {
			for (int j = 0; j < 3; j++) {
				rb[i][j] = rb[i+1][j];
			}
			rb[i][ a[i].second ] = a[i].first;
		}
		long long ans = 4e18;
		for (int i = 1; i <= len; i++) {
			if (a[i].second == 0) {
				ans = min(ans, val(lb[i][1], rb[i][2], a[i].first));
				ans = min(ans, val(lb[i][2], rb[i][1], a[i].first));
			} else if (a[i].second == 1) {
				ans = min(ans, val(lb[i][0], rb[i][2], a[i].first));
				ans = min(ans, val(lb[i][2], rb[i][0], a[i].first));
			} else {
				ans = min(ans, val(lb[i][1], rb[i][0], a[i].first));
				ans = min(ans, val(lb[i][0], rb[i][1], a[i].first));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}