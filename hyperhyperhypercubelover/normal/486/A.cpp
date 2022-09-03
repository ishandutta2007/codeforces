#include <cstdio>

int main() {
	long long n;
	scanf("%lld", &n);
	printf("%lld", n % 2 ? -(n + 1) / 2 : n / 2);
}