#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int m = 1000000007;

int pw(int x, int y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	int t = pw(x, y >> 1);
	t = t * 1ll * t % m;
	if (y & 1)
		t = t * 1ll * x % m;
	return t;
}

int inv(int x) {
	return pw(x, m-2);
}

int f[100005];
basic_string<int> divs[100005], pfs[100005];
int n;

int count_leq(int m, int x) {
	int k = pfs[m].size();
	int z = 0;
	for (int mask=0; mask<(1<<k); mask++) {
		int sgn = 1, prod = 1;
		for (int i=0; i<k; i++) {
			if (mask & (1 << i)) {
				sgn = -sgn;
				prod *= pfs[m][i];
			}
		}
		z += sgn * x / prod;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j+=i) {
			divs[j] += i;
			if (divs[i].size() == 2) {
				pfs[j] += i;
			}
		}
	}

	for (int i=2; i<=n; i++) {
		ll z = 0, self_c = n/i;
		for (int j : divs[i]) {
			if (j == i)
				continue;
			z += f[j] * 1ll * count_leq(i/j, n/j) % m;
		}
		z %= m;
		if (z < 0)
			z += m;
		f[i] = (1 + z*1ll*inv(n) % m) * inv(m + 1 - self_c*inv(n)%m) % m;
	}
	ll z = 0;
	for (int i=1; i<=n; i++) {
		z += f[i];
	}
	z %= m;
	cout << (1 + z*1ll*inv(n)) % m << '\n';
}