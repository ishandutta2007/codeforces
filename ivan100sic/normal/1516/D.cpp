// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct sieve {
	const int maxn;
	vector<int> f, primes;

	sieve(int maxn) : maxn(maxn), f(maxn) {
		for (int i=2; i<maxn; i++) {
			if (f[i] == 0) {
				f[i] = i;
				primes.push_back(i);
			}

			for (int p : primes) {
				if (p > f[i] || i * p >= maxn) {
					break;
				}

				f[i*p] = p;
			}
		}
	}

 	auto factor_small(int x) const {
		vector<pair<int, int>> v;
		while (x > 1) {
			int p = f[x], c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.emplace_back(p, c);
		}
		return v;
	}

	template<class T>
	auto factor(T x) const {
		vector<pair<T, int>> v;
		for (int p : primes) {
			if ((ll)p*p > x) {
				break;
			}

			if (x % p == 0) {
				int c = 0;
				while (x % p == 0) {
					x /= p;
					c++;
				}
				v.emplace_back(p, c);
			}
		}

		if (x > 1) {
			v.emplace_back(x, 1);
		}

		return v;
	}
} sv(100005);

int n, q, a[100005];
int last[100005];
int v[100005][18];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> q;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
		v[i][0] = v[i-1][0];
		for (auto [p, e] : sv.factor_small(a[i])) {
			if (last[p]) {
				v[i][0] = max(v[i][0], last[p]);
			}

			last[p] = i;
		}

		for (int j=1; j<18; j++) {
			v[i][j] = v[v[i][j-1]][j-1];
		}
  }

	for (int i=0; i<q; i++) {
		int l, r, z = 0;
		cin >> l >> r;
		for (int j=17; j>=0; j--) {
			if (v[r][j] >= l) {
				z += 1 << j;
				r = v[r][j];
			}
		}

		cout << z+1 << '\n';
	}

}