#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool isprime(i64 x) {
	for (i64 i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int T;
int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		i64 a, b;
		scanf("%lld%lld", &a, &b);
		if (a == b + 1 && isprime(a + b)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}