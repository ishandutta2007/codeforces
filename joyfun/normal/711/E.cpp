#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000003;

long long n, k;

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1LL * ans * x % MOD;
		x = 1LL * x * x % MOD;
		k >>= 1;
	}
	return ans;
}

int zi, mu;

long long a = 0;

int main() {
	scanf("%lld%lld", &n, &k);
	if (n <= 60) {
		long long ans = 1;
		for (int i = 0; i < n; i++) ans *= 2;
		if (k > ans) {
			printf("1 1\n");
			return 0;
		}
	}
	int tot = 1;
	int tmp = pow_mod(2, n % (MOD - 1));
	for (long long i = 1; i < k; i++) {
		long long cnt = 1, ii = i;
		while (ii % 2 == 0) {cnt *= 2; ii /= 2;}
		int aa = 1LL * (tmp - i + MOD) % MOD * pow_mod(cnt % MOD, MOD - 2) % MOD;
		tot = 1LL * tot * aa % MOD;
		if (tot == 0) break;
	}
	long long cnt = 0;
	long long kk = k - 1;
	while (kk) {
		cnt += kk / 2;
		kk /= 2;
	}
	n %= (MOD - 1); k--; k %= (MOD - 1); cnt %= (MOD - 1);
	int mi = (1LL * n * k % (MOD - 1) - cnt + MOD - 1) % (MOD - 1);
	int mu = pow_mod(2, mi);
	printf("%d %d\n", (mu - tot + MOD) % MOD, mu);
	return 0;
}