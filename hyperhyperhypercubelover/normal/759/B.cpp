#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];
int d[100001];

int main() {
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i] = min(min(d[i - 1] + 20, d[upper_bound(a, a + i, a[i] - 90) - a - 1] + 50), d[upper_bound(a, a + i, a[i] - 1440) - a - 1] + 120);
		printf("%d\n", d[i] - d[i - 1]);
	}
}