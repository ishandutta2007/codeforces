#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;

int main() {
	scanf("%d", &n);
	int x1, y1, x2, y2;
	x1 = INF, y1 = INF, x2 = -INF, y2 = -INF;
	int x, y;
	while (n--) {
		scanf("%d%d", &x, &y);
		x1 = min(x1, x);
		x2 = max(x2, x);
		y1 = min(y1, y);
		y2 = max(y2, y);
	}
	int ans = (y2 - y1) * (x2 - x1);
	if (ans == 0) ans = -1;
	printf("%d\n", ans);
	return 0;
}