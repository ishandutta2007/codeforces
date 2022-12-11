#include <algorithm>
#include <ostream>
#include <cstdio>

typedef long long LL;

int n, m;
int a[100010], b[100010], c[100010];

int main() {
	scanf("%d%d", &n, &m);
	LL sum = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		c[i] = a[i] - b[i];
		sum += a[i];
	}
	if(sum <= m) return puts("0"), 0;
	std :: sort(c+1, c+n+1, std :: greater<int>());
	for(int i=1; i<=n; i++) {
		sum -= c[i];
		if(sum <= m) return printf("%d\n", i), 0;
	}
	puts("-1");
	return 0;
}