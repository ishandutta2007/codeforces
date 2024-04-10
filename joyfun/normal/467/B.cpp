#include <cstdio>
#include <cstring>

int n, m, k;

int bitcount(int x) {
	int ans = 0;
	while (x) {
		ans += (x&1);
		x >>= 1;
	}
	return ans;
}

const int N = 1005;

int x[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", &x[i]);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (bitcount(x[i]^x[m]) <= k) ans++;
	}
	printf("%d\n", ans);
	return 0;
}