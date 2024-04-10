#include <cstdio>

int main() {
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) printf("%d", i & 1);
	return 0;
}