#include <cstdio>
#include <algorithm>

using namespace std;

int a[101];

int main() {
	int i, j, n, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	j = max_element(a, a + n) - a;
	for (i = j; i; i--) a[i] = a[i - 1];
	reverse(a + 1, a + n);
	printf("%d", j + min_element(a + 1, a + n) - a - 1);
}