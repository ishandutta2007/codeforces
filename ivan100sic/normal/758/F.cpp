// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 10000000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

ll solve(int n, int l, int r) {
	if (n == 1)
		return r-l+1;
	vector<int> c(r+1);
	ll z = 0;
	for (int x=l; x<=r; x++) {
		auto v = factor_small(x);
		int f = 1;
		for (auto [p, e] : v) {
			e %= n-1;
			while (e--)
				f *= p;
		}
		c[f]++;
	}
	for (int x : c)
		z += x*1ll*x;
	return z - (r-l+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, l, r;
	cin >> n >> l >> r;
	cout << solve(n, l, r) << '\n';
}

// I will still practice daily...