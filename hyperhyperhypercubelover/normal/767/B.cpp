#include <cstdio>

int main() {
	long long a, b, c, d, t;
	long long r = 9e18, rr;
	int n;
	scanf("%lld%lld%lld%d", &a, &b, &c, &n);
	d = 0;
	while (n--) {
		scanf("%lld", &t);
		if (t > b - c + 1) t = b - c + 1;
		a = a + d - t + 1;
		if (a < 0) a = 0;
		if (a + t + c > b + 1) break;
		if (a < r) {
			r = a;
			rr = t - 1;
		}
		a += c - !!a;
		d = t;
	}
	if (n < 0) {
		t = b - c;
		a = a + d - t;
		if (a <= 0) rr = t;
	}
	printf("%lld", rr);
}