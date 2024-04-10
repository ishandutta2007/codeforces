// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<size_t>(new int) + *(new unsigned long));

int n;
ll a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sieve sito(1000005);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);
	int k = 0;
	while (k < n && a[k] == 1)
		k++;

	if (k == n)
		return cout << n, 0;

	uniform_int_distribution<int> uid(k, n-1);

	volatile bool radi = true;

	thread([&]() {
		this_thread::sleep_for(2100ms);
		radi = false;
	}).detach();

	ll sol = n;

	while (radi) {
		ll xb = a[uid(eng)];
		for (ll x=max(1ll, xb-1); x<=xb+1; x++) {
			auto v = sito.factor(x);
			// da li sam ja realan??????
			for (auto [p, we] : v) {
				ll q = 0;
				for (int i=0; i<n; i++) {
					ll d = a[i] % p;
					if (d < p-d) {
						if (a[i] < p)
							q += p-d;
						else
							q += d;
					} else {
						q += p-d;
					}
				}
				sol = min(sol, q);
			}
		}
	}

	cout << sol << '\n';
}

// I will still practice daily...