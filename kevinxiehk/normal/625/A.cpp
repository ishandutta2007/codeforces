#include <algorithm>
#include <cstdio>
using namespace std;

int main () {
	long long n, a, b, c;
	scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
	if (a <= b - c) {
		printf("%lld\n", n / a);
	} else {
		if (n < b) {
			printf("%lld\n", n / a);
		} else {
			long long glass = (n - c) / (b - c);
			n -= glass * (b - c);
			printf("%lld\n", glass + max(n / a, n / b));
		}
	}
	return 0;
}