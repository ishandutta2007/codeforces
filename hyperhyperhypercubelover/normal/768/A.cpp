#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main() {
	int i, n, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = 0; i < n; i++) if (a[0] < a[i] && a[i] < a[n - 1]) r++;
	printf("%d", r);
}