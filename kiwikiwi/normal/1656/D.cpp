#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

i64 n;
i64 solve() {
	scanf("%lld", &n);
	if (n % 2 == 1) return 2;
	i64 m = 1;
	while (n % 2 == 0) {
		n /= 2;
		m *= 2;
	}
	if (n == 1) return -1;
	return min(m * 2, n);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		printf("%lld\n", solve());
	}
}