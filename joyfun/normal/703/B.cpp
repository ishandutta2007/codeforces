#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
typedef long long ll;
int n, k;
ll c[N];
int vis[N];

int main() {
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
		memset(vis, 0, sizeof(vis));
		ll sum = 0;
		int x;
		ll ans = 0;
		for (int i = 1; i <= k; i++) {
			scanf("%d", &x);
			vis[x] = 1;
			ans += c[x] * sum;
			sum += c[x];
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			ans += c[i] * sum;
			int j = i + 1;
			if (j == n + 1) j = 1;
			if (!vis[j]) ans += c[i] * c[j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}