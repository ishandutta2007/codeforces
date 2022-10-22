#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, k, a[maxn], s[maxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		s[i] = i;
	}
	int lead = 1, now = n;
	for (int i = 1; i <= k; i++) {
		int k = (lead + a[i]) % now;
		if (!k) {
			k = now;
		}
		printf("%d ", s[k]);
		for (int j = k + 1; j <= n; j++) {
			s[j - 1] = s[j];
		}
		lead = k == now ? 1 : k;
		now--;
	}
	return 0;
}