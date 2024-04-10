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

sieve sv(3000);
vector<int> primes = sv.primes;
int queries = 0;

ll ask(ll x) {
	queries++;
	cout << "? " << x << '\n' << flush;
	cin >> x;
	return x;
}

void ans(ll x) {
	cout << "! " << x << '\n' << flush;
}

const ll lim_ll = 1'000'000'000'000'000'000ll;
const ll lim_int = 1'000'000'000ll;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		queries = 0;
		ll rem = lim_int;
		int k = 0;
		vector<int> pr;
		int divs = 1;

		while (9) {
			ll prod = 1;
			while (prod <= lim_ll / primes[k])
				prod *= primes[k++];

			ll resp = ask(prod);
			rem /= resp;
			for (int p : primes) {
				if (resp % p == 0) {
					pr.push_back(p);
				}
			}

			if (queries == 22) {
				divs = 4;
				break;
			}

			auto solve_prime = [&](int p) {
				if (queries == 22)
					return;
				ll q = 1;
				while (q * p <= lim_int)
					q *= p;
				ll r = ask(q);
				ll r0 = r;
				int c = 1;
				while (r % p == 0)
					r /= p, c++;
				divs *= c;
				rem /= r0 / p;
			};

			while (pr.size() >= 2) {
				int p1 = pr[pr.size() - 1], p2 = pr[pr.size() - 2];
				pr.resize(pr.size() - 2);

				solve_prime(p1);
				solve_prime(p2);
			}

			if (1ll * primes[k] * primes[k+1] * primes[k+2] > rem) {
				if (pr.size())
					solve_prime(pr[0]);
				break;
			}
		}

		ans(2*divs);

	}
}