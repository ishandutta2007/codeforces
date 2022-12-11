#include <cstdio>
#include <cmath>

int n, a[100010], min_t(1e9+1), ans(1);

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1, t; i<=n; i++) {
		a[i] -= i-1;
		if(a[i] < 0) a[i] = 0;
		t = ceil(a[i] * 1.0 / n);
		if(t < min_t) min_t = t, ans = i;
	}
	printf("%d\n", ans);
	return 0;
}