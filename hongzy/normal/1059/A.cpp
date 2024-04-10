#include <cstdio>

int main() {
	int n, l, a;
	scanf("%d %d %d", &n, &l, &a);
	int last(0), ans(0);
	for(int i = 1, L, len; i <= n; ++ i) {
		scanf("%d %d", &L, &len);
		ans += (L - last) / a;
		last = L + len;
	}
	printf("%d\n", ans += (l - last) / a);
	return 0;
}