#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int main(void) {
	int minx, maxx, miny, maxy, minu, maxu, minv, maxv;
	miny = minx = minu = minv = INT_MAX;
	maxx = maxy = maxu = maxv = INT_MIN;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
		minv = min(minv, x + y);
		maxv = max(maxv, x + y);
		minu = min(minu, x - y);
		maxu = max(maxu, x - y);
	}
	--minx; --miny; --minu; --minv;
	++maxx; ++maxy; ++maxu; ++maxv;
	int res = 0;
	res += max(0, (minx - minu) - (minv - minx));
	res += max(0, (maxv - maxx) - (maxx - maxu));
	res += 2 * (maxx - minx);
	printf("%d\n", res);
	return 0;
}