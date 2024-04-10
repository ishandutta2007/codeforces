#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

int n;

map<i64, int> fac, rem;
set<i64> posp;
vector<i64> p4;

i64 gcd(i64 a, i64 b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

bool check(i64 a, int b) {
	b -= 1;
	i64 c = pow(a, 1.0 / b) - 0.1;
	while (true) {
		i64 s = 1;
		for (int i = 0; i < b; i++)
			s = s * c;
		if (s > a) return 0;
		if (s == a) {
			fac[c] += b;
			return 1;
		}
		c += 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		i64 x;
		scanf("%lld", &x);
		for (int j = 5; j >= 3; j--) {
			if (check(x, j)) {
				x = 0;
				break;
			}
		}
		if (x != 0) {
			p4.push_back(x);
		}
	}
	for (auto p : fac) {
		posp.insert(p.first);
	}
	for (auto p : p4) for (auto q : p4)
			if (p < q) {
				auto w = gcd(p, q);
				if (w != 1) posp.insert(w);
			}
	for (auto p : p4) {
		bool suc = 0;
		for (auto q : posp) if (p % q == 0) {
				fac[q]++;
				fac[p / q]++;
				suc = 1;
				break;
			}
		if (!suc) {
			rem[p]++;
		}
	}
	i64 ans = 1;
	for (auto p : fac) {
		ans = ans * (p.second + 1) % mod;
	}
	for (auto p : rem) {
		ans = ans * (p.second + 1) * (p.second + 1) % mod;
	}
	printf("%lld\n", ans);
}