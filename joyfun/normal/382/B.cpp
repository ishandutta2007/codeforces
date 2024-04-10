#include <stdio.h>
#include <string.h>
#include <math.h>

long long a, b, w, x, c;

long long solve() {
	if (c <= a) return 0;
	long long ans = (long long)ceil((x * (c - a) - b) * 1.0 / (w - x)) + (c - a);
	return ans;
}

int main() {
	scanf("%lld%lld%lld%lld%lld", &a, &b, &w, &x, &c);
	printf("%lld\n", solve());
	return 0;
}