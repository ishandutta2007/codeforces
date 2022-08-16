#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void print(int j) {
	while (j--) {
		putc('(', stdout);
		putc(')', stdout);
	}
}

void out(ll n, ll k) {
	if (k == 0) {
		print(n);
		return;
	}
	if (k < n-1) {
		putc('(', stdout);
		print(k);
		putc(')', stdout);
		print(n - k-1);
		return;
	}
	putc('(', stdout);
	out(n-1, k-n+1);
	putc(')', stdout);
}

int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if (n*(n-1)/2 < k) {
		printf("Impossible\n");
		return 0;
	}
	out(n, k);
	putc('\n', stdout);

	return 0;
}