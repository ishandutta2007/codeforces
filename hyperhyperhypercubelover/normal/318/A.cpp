#include <cstdio>

int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld", b > (a + 1) / 2 ? b - (a + 1) / 2 << 1 : b + b - 1);
}