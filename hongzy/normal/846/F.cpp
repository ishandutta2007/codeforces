#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, pos[1000005];
int main() {
	register int i, a; scanf("%d", &n); long long ans = - n;
	for(i = 1, a; i <= n; i ++) {
		scanf("%d", &a);
		if(!pos[a]) {
			ans += n * (n + 1ll);
			m = max(m, a);
		}
		ans -= (i - pos[a]) * (i - pos[a] - 1ll);
		pos[a] = i;
	}
	for(i = 1; i <= m; i ++) if(pos[i])
		ans -= (n + 1ll - pos[i]) * (n - pos[i]);
	printf("%.6f", ans * 1.0 / n / n);
	return 0;
}