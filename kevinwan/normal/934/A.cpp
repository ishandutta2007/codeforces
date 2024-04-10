#include <bits/stdc++.h>
using namespace std;
long long a[50], b[50];
int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)scanf("%lld", a + i);
	for (i = 0; i < m; i++)scanf("%lld", b + i);
	sort(a, a + n);
	sort(b, b + m);
	long long aa = max(max(a[1] * b[0], a[n - 1] * b[m - 1]), max(a[1] * b[m - 1], a[n - 1] * b[0])),bb= max(max(a[0] * b[0], a[n - 2] * b[m - 1]), max(a[0] * b[m - 1], a[n - 2] * b[0]));
	printf("%lld", min(aa,bb));
	getchar(); getchar();
}