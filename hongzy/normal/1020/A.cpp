#include <cstdio>
#include <algorithm>

using std :: abs;
using std :: min;

int n, h, a, b, q;

int main() {
	scanf("%d%d%d%d%d", &n, &h, &a, &b, &q);
	for(int i = 1; i <= q; i ++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2) {
			printf("%I64d\n", 1ll*abs(y1 - y2));
			continue ;
		}
		long long ans = (1ll << 58);
		if((y1 >= a && y1 <= b) || (y2 >= a && y2 <= b)) ans = min(ans, 1ll*abs(y2 - y1));
		ans = min(ans, 1ll*abs(a - y1) + abs(a - y2));
		ans = min(ans, 1ll*abs(b - y1) + abs(b - y2));
		printf("%I64d\n", ans + 1ll*abs(x1 - x2));
	}
	return 0;
}