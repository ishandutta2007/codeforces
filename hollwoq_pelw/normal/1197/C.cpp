#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

int n, k;
int a[N], b[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	sort(b + 1, b + n);
	int ans = a[n] - a[1];
	for (int i = 1; i < k; i++) {
		ans -= b[n - i];
	}
	printf("%d\n", ans);
	return 0;
}