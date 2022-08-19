#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 a, b, c;
int main() {
	scanf("%lld%lld%lld", &a, &b, &c);
	if (a == b) {
		printf("%lld\n", 2 * c + 2 * min(a, b));
	} else {
		printf("%lld\n", 2 * c + 2 * min(a, b) + 1);
	}
}