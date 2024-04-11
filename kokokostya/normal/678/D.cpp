#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M = 1000000007;

int main() {
	int a, b, x;
	long long n;
	cin >> a >> b >> n >> x;
	long long ans = 0;
	if (a == 1) {
		n %= M;
		n *= b;
		n %= M;
		n += x;
		n %= M;
		cout << n;
	}
	else {
		long long res = 1;
		long long now = a;
		while (n) {
			if (n & 1) { res *= now; }
			now *= now;
			now %= M;
			res %= M;
			n >>= 1;
		}
		ans += (res * x) % M;
		res--;
		if (res < 0) { res += M; }
		res *= b;
		res %= M;
		long long res2 = 1;
		long long now2 = a - 1;
		int m = M - 2;
		while (m) {
			if (m & 1) { res2 *= now2; }
			now2 *= now2;
			now2 %= M;
			res2 %= M;
			m >>= 1;
		}
		res *= res2;
		res %= M;
		ans += res;
		ans %= M;
		cout << ans;
	}
	return 0;
}