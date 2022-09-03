#include <cstdio>

int a[100001];

int main() {
	int i, n, m, t;
	scanf("%d", &n);
	m = n;
	while (n--) {
		scanf("%d", &t);
		a[t] = 1;
		while (m && a[m]) printf("%d ", m--);
		puts("");
	}
}