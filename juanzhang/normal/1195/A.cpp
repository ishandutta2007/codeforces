#include <bits/stdc++.h>
using namespace std;

int n, k, a[1010], c[1010];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i), c[a[i]]++;
	}
	int m = 0;
	for (int i = 1; i <= k; i++) {
		if (c[i] & 1) {
			m++;
		}
	}
	printf("%d", n - (m / 2));
	return 0;
}