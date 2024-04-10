#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long LL;

const LL max_lcm = 2520;

int buf[22], len;
int _hash[2521];

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}

LL f[22][2521][51];

LL dfs(LL k, bool lim, LL d, LL _lcm) {
	if(k == 0) return d % _lcm == 0;
	if(!lim && ~f[k][d][_hash[_lcm]]) return f[k][d][_hash[_lcm]];
	LL ans = 0;
	int r = lim ? buf[k] : 9;
	for(int i=0; i<=r; i++) {
		LL nd = (d * 10 + i) % max_lcm;
		LL n_lcm = i == 0 ? _lcm : lcm(_lcm, i);
		ans += dfs(k - 1, lim && (i == r), nd, n_lcm);
	}
	if(!lim) f[k][d][_hash[_lcm]] = ans;
	return ans;
}

LL work(LL x) {
	len = 0;
	do buf[++ len] = x % 10, x /= 10;
	while(x);
	return dfs(len, true, 0, 1);
}

void init() {
	for(int i=1, id=0; i<=max_lcm; i++)
		if(max_lcm % i == 0) _hash[i] = ++ id;
	memset(f, -1, sizeof f);
}

int main() {
	int T; init();
	scanf("%d", &T);
	while(T --) {
		LL l, r;
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", work(r) - work(l-1));
	}
	return 0;
}