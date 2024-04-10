#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long x, l, r, t;
	int i, n, R = 0;
	scanf("%lld%lld%lld", &x, &l, &r);
	for (n = 1; x >> n; n++);
	for (t = l; t <= r; t++) {
		for (i = 0; !(t >> i & 1); i++);
		R += x >> (n - i - 1) & 1;
	}
	printf("%d", R);
}