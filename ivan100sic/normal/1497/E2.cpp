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
};

sieve sv(10000005);

int sqh(int x) {
	auto v = sv.factor_small(x);
	int y = 1;
	for (auto [p, e] : v) {
		if (e & 1) {
			 y *= p;
		}
	}
	return y;
}

int a[200005];
int dp[200005][23];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

		map<int, int> mp;

		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			x = sqh(x);

			if (mp.count(x)) {
				a[i] = mp[x];
			} else {
				a[i] = -1;
			}
			mp[x] = i;
		}

		for (int i=0; i<=n+1; i++) {
			for (int j=0; j<=k+1; j++) {
				dp[i][j] = 1e9;
			}
		}
		dp[0][0] = 0;

		multiset<int> sl;

		for (int i=1; i<=n; i++) {
			// dodaj
			if (a[i-1] != -1) {
				sl.insert(a[i-1]);
			}

			auto it = sl.end();
			vector<int> pl;
			for (int i=0; i<=k; i++) {
				if (it == sl.begin()) {
					break;
				}
				--it;
				pl.push_back(*it + 1);
			}

			if (pl.size() == sl.size()) {
				pl.push_back(0);
			}

			for (int j=0; j<=k; j++) {
				for (int d=0; d<=min((int)pl.size() - 1, k-j); d++) {
					dp[i][j+d] = min(dp[i][j+d], dp[pl[d]][j] + 1);
				}
			}
		}

		cout << *min_element(dp[n], dp[n] + k + 1) << '\n';
  }
}