#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 gcd(i64 a, i64 b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


i64 n, m, k;
int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	if (2 * n * m % k != 0) {
		puts("NO");
	} else {
		i64 s = 2 * n * m / k;
		i64 d = gcd(s, n);
		if (d < n && s / d % 2 == 0) d = d * 2;
		assert(s % d == 0 && s / d <= m);
		printf("YES\n0 0\n%lld 0\n0 %lld\n", d, s / d);
	}
}