#include <bits/stdc++.h>
using namespace std;

const int N = 223456;

int n, s, a[N];
long long ans;
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int x = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		if (i < x) ans += max(a[i] - s, 0);
		else if (i == x) ans += abs(a[i] - s);
		else ans += max(s - a[i], 0);
	}
	printf("%lld\n", ans);
}