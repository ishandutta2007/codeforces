#include <iostream>
#include <algorithm>
using namespace std;

long long md = 998244353;

struct dn
{
	long long a, b;
	dn(long long a, long long b) : a(a), b(b) {};
	dn() : a(0LL), b(1LL) {};
	dn operator+(const dn &r) const {
		return dn((a * r.b + r.a * b) % md, (b * r.b) % md);
	}
	dn operator*(const dn &r) const {
		return dn((a * r.a) % md, (b * r.b) % md);
	}
};

long long sp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k % 2) s = (s * n) % md;
		k /= 2; n = (n * n) % md;
	}
	return s;
}

dn pr[1000009];
long long pc[1000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			pc[a]++;
			pr[a] = pr[a] + (dn(1LL, 1LL * n) * dn(1LL, 1LL * k));
		}
	}
	dn ans = dn(0, 1);
	for (int i = 1; i <= 1000000; i++) {
		if (pc[i] == 0) continue;
		ans = ans + (pr[i] * dn(pc[i], 1LL * n));
	}
	cout << (ans.a * sp(ans.b, md - 2)) % md << '\n';
	return 0;
}