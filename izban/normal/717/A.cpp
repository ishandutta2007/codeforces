#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;
const int MOD = (int)(1e9) + 7;
const int MAXN = 1 << 10;

void work() {
	int n = 30;
	vector<int> f(n);
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	vector<int> g(n);
	g[0] = 0;
	for (int i = 1; i < n; i++) {
		g[i] = g[i - 1] + f[i] * f[i];
	}

	for (int i = 0; i < MOD; i++) {
		if (i % 1000000 == 0) cerr << i << endl;
		if (1LL * i * i % MOD == 5) {
			cout << i << endl;
			exit(0);
		}
	}
	return;
}

int bin(int a, ll n) {
	int res = 1;
	while (n) {
		if (n & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		n >>= 1;
	}
	return res;
}

int inv(int x) {
	return bin(x, MOD - 2);
}

int fct[MAXN];
int ofct[MAXN];
int fib[MAXN];

int getC(int n, int k) {
	if (n < 0 || k > n || k < 0) return 0;
	return fct[n] * 1LL * ofct[k] % MOD * ofct[n - k] % MOD;
}

void init() {
	fct[0] = 1;
	for (int i = 1; i < MAXN; i++) fct[i] = 1LL * fct[i - 1] * i % MOD;
	for (int i = 0; i < MAXN; i++) ofct[i] = inv(fct[i]);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

/*const int K = 210;
struct matrix {
	int a[K][K];

	matrix operator* (const matrix &m) const {
		matrix res;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				res.a[i][j] = 0;
				for (int k = 0; k < K; k++) {
					res.a[i][j] = (res.a[i][j] + 1LL * a[i][k] * m.a[k][j]) % MOD;
				}
			}
		}
		return res;
	}
};

matrix bin(matrix a, int n) {
	matrix res;
	for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) res.a[i][j] = i == j;
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}
*/
struct num {
	int a, b;

	num() {}
	num(int _a, int _b) : a(_a), b(_b) {}

	num operator+ (const num &n) const {
		return num((a + n.a) % MOD, (b + n.b) % MOD);
	}

	num operator- (const num &n) const {
		return num((a - n.a + MOD) % MOD, (b - n.b + MOD) % MOD);
	}

	num operator* (const num &n) const {
		return num((1LL * a * n.a + 5 * 1LL * b * n.b) % MOD, (1LL * a * n.b + 1LL * b * n.a) % MOD);
	}

	num conj() const {
		return num(a, (MOD - b) % MOD);
	}

	num operator/ (const num &n) const {
		num o = n * n.conj();
		assert(o.b == 0);
		return ((*this) * n.conj()) / o.a;
	}

	num operator* (int d) const {
		return num(1LL * a * d % MOD, 1LL * b * d % MOD);
	}

	num operator/ (int d) const {
		assert(d != 0);
		int od = inv(d);
		return (*this) * od;
	}
};

num bin(num a, ll n) {
	num res(1, 0);
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int sumfibk(ll n, int k) {
	num a = num(1, 1) / 2;
	num b = num(1, MOD - 1) / 2;
	
	num res(0, 0);
	for (int i = 0; i <= k; i++) {
		num t = bin(a, i) * bin(b, k - i);
		num o;
		if (t.a == 1 && t.b == 0) {
			o = t * ((n + 1) % MOD);
		}
		else {
			o = (num(1, 0) - bin(t, n + 1)) / (num(1, 0) - t);
		}
		res = res + o * getC(k, i) * ((k - i) % 2 == 1 ? MOD - 1 : 1);
	}
	res = res / bin(num(0, 1), k);
	assert(res.b == 0);
	return res.a;
}

int sumfibk(ll l, ll r, int k) {
	return (sumfibk(r, k) - sumfibk(l - 1, k) + MOD) % MOD;
}

// c(fib[3], k) + ... + c(fib[n+2], k)
ll sum(int k, ll n) {
	vector<int> cur(1, 1);
	for (int t = 0; t < k; t++) {
		cur.push_back(0);
		for (int i = (int)cur.size() - 2; i >= 0; i--) {
			cur[i + 1] = (cur[i + 1] + cur[i]) % MOD;
			cur[i] = 1LL * cur[i] * (MOD - t) % MOD;
		}
	}
	int ans = 0;
	for (int i = 0; i < (int)cur.size(); i++) {
		ans = (ans + 1LL * cur[i] * sumfibk(3, n + 2, i)) % MOD;
	}
	ans = 1LL * ans * ofct[k] % MOD;
	return ans;
}

int slow(int k, int n) {
	int ans = 0;
	for (int i = 3; i <= n + 2; i++) ans = (ans + getC(fib[i], k)) % MOD;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	//work();
	init();

	if (0) for (int n = 1; n <= 10; n++) {
		for (int k = 1; k <= 10; k++) {
			cerr << n << " " << k << endl;
			int ans1 = sum(k, n);
			int ans2 = slow(k, n);
			if (ans1 != ans2) {
				cerr << ans1 << " instead of " << ans2 << endl;
				sum(k, n);
				slow(k, n);
				return 0;
			}
		}
	}

	int k;
	ll l, r;
	while (cin >> k >> l >> r) {
		cout << (sum(k, r) - sum(k, l - 1) + MOD) % MOD << endl;
	}

	return 0;
}