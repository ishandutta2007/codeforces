#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;


const int N = 100005;
const int INF = 0x3f3f3f3f;

int n, l, x, y, a[N];

bool judge(int x) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		while (r < n && a[r] - a[i] < x) r++;
		if (a[r] - a[i] == x) return true;
	}
	return false;
}

bool ck(int x) {
	if (x < 0 || x > l) return false;
	int v = lower_bound(a, a + n, x + y) - a;
	if (v >= 0 && v < n && a[v] == x + y) return true;
	v = lower_bound(a, a + n, x - y) - a;
	if (v >= 0 && v < n && a[v] == x - y) return true;
	return false;
}

void gao() {
	for (int i = 0; i < n; i++) {
		if (ck(a[i] + x)) {
			printf("1\n%d\n", a[i] + x);
			return;
		}
		if (ck(a[i] - x)) {
			printf("1\n%d\n", a[i] - x);
			return;
		}
	}
	printf("2\n%d %d\n", x, y);
}

int main() {
	scanf("%d%d%d%d", &n, &l, &x, &y);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int f1 = judge(x), f2 = judge(y);
	if (f1 && f2) printf("0\n");
	else if (f1 || f2) {
		printf("1\n");
		if (f1) printf("%d\n", y);
		if (f2) printf("%d\n", x);
	} else gao();
	return 0;
}