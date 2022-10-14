#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long n, k, pw, ans = 1, nt;
long long dp[1019];

long long modpow(long long n, long long pow) {
	n%=mod;
	if (pow == 0)
		return 1;
	if (pow & 1)
		return (n * 1ll * modpow(n, pow ^ 1)) % mod;
	return modpow(n * 1ll * n, pow >> 1) % mod;
}

long long f(long long p, long long a) {
	for (int i = 0; i <= a; i++) {
		dp[i] = modpow(p, i);
	}
	long long s;
	for (long long i = 0; i < k; i++) {
		s = 0;
		for (int j = 0; j <= a; j++) {
			s += dp[j];
			s %= mod;
			dp[j] = s * modpow(j + 1, mod - 2);
			dp[j] %= mod;
		}
	}
	return dp[a];
}

int main() {
	cin >> n >> k;
	nt = n;
	for (long long i = 2; i * i <= nt; i++) {
		if (nt % i)
			continue;
		pw = 0;
		while (!(nt % i))
			nt /= i, pw++;
		ans *= f(i, pw);
		ans %= mod;
	}
	if(nt != 1) {
		ans *= f(nt, 1);
		ans %= mod;
	}
	cout << ans;
	return 0;
}