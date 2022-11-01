#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int f[N], a[N];
int T, n, x;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), f[i] = 0;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			int cnt = (x - 1) / a[i];
			if (i + cnt <= n) f[i + cnt] = max(f[i + cnt], f[i - 1] + 1);
			f[i] = max(f[i], f[i - 1]);
		}
		printf("%d\n", f[n]);
	}
	return 0;
}