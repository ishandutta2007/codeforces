#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, sum, a[maxn];

int main() {
	int mx = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum += a[i], mx = max(mx, a[i]);
	}
	for (int i = mx; ; i++) {
		if (i * n - sum > sum) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}