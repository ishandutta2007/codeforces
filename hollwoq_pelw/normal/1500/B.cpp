#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 1e6 + 5;

int n, m, posa[N], posb[N];
long long k;

vector<long long> v;

long long egcd(long long a, long long b, long long &x, long long &y) {
	if (!b) return x = 1, y = 0, a;
	long long g = egcd(b, a % b, y, x);
	return y -= (a / b) * x, g;
}

long long crt(long long a, long long n, long long b, long long m) {
	if (n > m) swap(a, b), swap(n, m);
	long long x, y, g = egcd(n, m, x, y);
	x = (b - a) % m * x % m / g * n + a;
	return x < 0 ? x + m / g * n : x;
}

void solve_case() {
	memset(posa, -1, sizeof posa);
	memset(posb, -1, sizeof posb);

	cin >> n >> m >> k;
	for (int i = 0, x; i < n; i++)
		cin >> x, posa[x] = i;
	for (int i = 0, x; i < m; i++)
		cin >> x, posb[x] = i;
	long long g = __gcd(n, m), lcm = 1ll * n / g * m;

	for (int i = 1; i < N; i++) if (posa[i] >= 0 && posb[i] >= 0) {
		if (posa[i] % g == posb[i] % g)
			v.emplace_back(crt(posa[i], n, posb[i], m));
	}

	long long l = 1, r = 2e18;

	while (l < r) {
		long long mid = (l + r) >> 1, tot = mid;

		for (long long x : v)
			tot -= mid / lcm + (x < mid % lcm);

		// cout << mid << ' ' << tot << '\n';

		if (tot >= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l;
}