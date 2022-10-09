#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
long long a[305];
int used[305];

int b[305], d;

bool kv(long long x) {
	long long l = 1, r = 1'000'000'001;

	while (l <= r) {
		long long m = (l+r) / 2;

		if (m * m > x) {
			r = m-1;
		} else if (m * m < x) {
			l = m+1;
		} else {
			return true;
		}
	}

	return false;
}

const long long MOD = 1'000'000'007;

long long pw(long long a, long long b) {
	if (b == 0) {
		return 1;
	}

	long long t = pw(a, b/2);
	t = t*t % MOD;

	if (b % 2 == 1) {
		t = t*a % MOD;
	}

	return t;
}

long long inv(long long x) {
	return pw(x, MOD-2);
}

long long f[305], finv[305];

void init() {
	f[0] = finv[0] = 1;
	for (int i=1; i<305; i++) {
		f[i] = f[i-1] * i % MOD;
		finv[i] = inv(f[i]);
	}
}

long long dp[305][305];

long long bink(int n, int k) {
	if (n < 0 || n < k) return 0;
	return f[n] * finv[k] % MOD * finv[n-k] % MOD;
}

long long parity(int x) {
	if (x % 2) {
		return MOD-1;
	} else {
		return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init();

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		if (!used[i]) {
			int c = 0;
			for (int j=1; j<=n; j++) {
				if (kv(a[i] * a[j])) {
					c++;
					used[j] = 1;
				}
			}
			b[++d] = c;
		}
	}

	/*
	for (int i=1; i<=d; i++) {
		cerr << b[i] << '\n';
	}
	*/

	long long f1 = 1;

	for (int r=0; r<=n; r++) {
		dp[r][1] = bink(r+1, b[1]) * f[r] % MOD;
	}

	for (int i=2; i<=d; i++) {
		for (int r=0; r<=n-b[i]; r++) {
			for (int j=1; j<=b[i]; j++) {
				dp[r][i] += parity(b[i] - j) * finv[j] % MOD
					* bink(b[i]-1, j-1) % MOD * dp[r+j][i-1] % MOD;

				dp[r][i] %= MOD;
			}
		}
	}

	long long sol = dp[0][d];

	cerr << sol << '\n';

	for (int i=1; i<=d; i++) {
		sol = sol * f[b[i]] % MOD;
	}

	cout << sol;

}