#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;

int n, a[N], b[N], cnt[N], m;
ll k;

int main() {
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) {
		if(i == 1 || a[i] != a[i - 1]) {
			b[++ m] = a[i]; cnt[m] = 1;
		} else {
			cnt[m] ++;
		}
	}
	ll rk = 0;
	for(int i = 1; i <= m; i ++) {
		rk += cnt[i] * 1ll * n;
		if(k <= rk) {
			rk -= cnt[i] * 1ll * n;
			k -= rk;
			k = (k + cnt[i] - 1) / cnt[i];
			printf("%d %d\n", b[i], a[k]);
			break ;
		}
	}
	return 0;
}