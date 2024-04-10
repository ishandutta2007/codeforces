#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d1, d2, d3;

int main() {
	while (~scanf("%d%d%d", &d1, &d2, &d3)) {
		int ans = min(d1 + d1 + d2 + d2, d1 + d2 + d3);
		ans = min(ans, d1 + d1 + d3 + d3);
		ans = min(ans, d2 + d2 + d3 + d3);
		printf("%d\n", ans);
	}
	return 0;
}