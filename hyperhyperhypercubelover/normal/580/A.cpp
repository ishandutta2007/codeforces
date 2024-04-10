#include <cstdio>

int main() {
	int n, a, b, t, r;
	scanf("%d", &n);
	t = r = 0;
	a = 1e9;
	while (n--) {
		scanf("%d", &b);
		if (a > b) t = 0;
		t++;
		if (t > r) r = t;
		a = b;
	}
	printf("%d", r);
}