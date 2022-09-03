#include <cstdio>

int main() {
	int n, a, b, r = 1;
	scanf("%d%d", &n, &a);
	while (--n) {
		scanf("%d", &b);
		r += a != b;
		a = b;
	}
	printf("%d", r);
}