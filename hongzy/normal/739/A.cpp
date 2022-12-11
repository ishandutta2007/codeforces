#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];
int main() {
	scanf("%d%d", &n, &m);
	int l, r, x = n, c = 0;
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d", &l, &r);
		x = min(x, r - l + 1);
	}
	printf("%d\n", x);
	for(int i = 1; i <= n; i ++) {
		printf("%d ", c);
		c = c == x - 1 ? 0 : c + 1;
	}
	return 0;
}