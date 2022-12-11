#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
const int N = 1010;
int n, m, k, p, a[N][N];
multiset<ll> sx, sy;
ll ans(-1e17), ax[N * N], ay[N * N];
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++) {
		ll s = 0;
		for(int j = 1; j <= m; j ++) s += a[i][j];
		sx.insert(s);
	}
	for(int j = 1; j <= m; j ++) {
		ll s = 0;
		for(int i = 1; i <= n; i ++) s += a[i][j];
		sy.insert(s);
	}
	for(int i = 1; i <= k; i ++) {
		ll x = * -- sx.end();
		ax[i] = ax[i - 1] + x;
		sx.erase(-- sx.end());
		sx.insert(x - p * m);
	}
	for(int i = 1; i <= k; i ++) {
		ll y = * -- sy.end();
		ay[i] = ay[i - 1] + y;
		sy.erase(-- sy.end());
		sy.insert(y - p * n);
	}
	for(int i = 0; i <= k; i ++)
		ans = max(ans, ax[i] + ay[k - i] - 1ll * i * (k - i) * p);
	printf("%I64d\n", ans);
	return 0;
}