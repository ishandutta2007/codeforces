#include <bits/stdc++.h>
using namespace std;

#prag\
ma GCC optimize(3)
#define re register int
typedef long long ll;
const int maxn = 1e5 + 10;
int tot, prime[maxn]; bool mark[maxn];

inline void sieve() {
	const int t = sqrt(100000);
	for (re i = 2; i <= t; i++) {
		if (!mark[i]) {
			for (re j = i * i; j < 100001; j += i) {
				mark[j] = 1;
			}
		}
	}
	for (re i = 2; i < 100001; i++) {
		if (!mark[i]) prime[++tot] = i;
	}
}

inline ll factor(const ll& x) {
	const int t = sqrt(x);
	for (re i = 1; i <= tot && prime[i] <= t; i++) {
		if (x % prime[i] == 0) return prime[i];
	}
	return x;
}

int main() {
	sieve();
	int ans = 0; ll x;
	scanf("%lld", &x);
	while (x & 1) x -= factor(x), ans++;
	printf("%lld", ans + (x >> 1));
	return 0;
}