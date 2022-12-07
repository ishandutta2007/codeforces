#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
__int64 n, m, k;

bool judge(__int64 mid) {
	__int64 sum = 0;
	for (__int64 i = 1; i <= n; i++) {
		sum += min(m, (mid / i));
	}
	return sum >= k;
}

__int64 solve() {
	__int64 l = 1, r = n * m;
	while (l < r) {
		__int64 mid = (l + r) / 2;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	if (n > m) {
		__int64 t = n;
		n = m;
		m = t;
	}
	printf("%I64d\n", solve());
	return 0;
}