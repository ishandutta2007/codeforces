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

sieve s(33333);

void divs(vector<pair<int, int>>& v, int d, int x, vector<int>& s) {
	if (d == (int)v.size()) {
		s.push_back(x);
		return;
	}

	for (int i=0; i<=v[d].second; i++) {
		divs(v, d+1, x, s);
		if (i < v[d].second) x *= v[d].first;
	}
}

vector<int> divs(vector<pair<int, int>>& v) {
	vector<int> s;
	divs(v, 0, 1, s);
	return s;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		auto v = s.factor(x);
		if (v.size() == 1) {
			for (ll t=v[0].first; t<=x; t*=v[0].first) {
				cout << t << ' ';
			}
			cout << "\n0\n";
		} else if (v.size() == 2 && v[0].second == 1 && v[1].second == 1) {
			cout << x << ' ' << v[0].first << ' ' << v[1].first << "\n1\n";
		} else {
			auto d = divs(v);
			d.erase(find(begin(d), end(d), 1));
			vector<int> delims(v.size());
			vector<vector<int>> parts(v.size());

			for (int i=0; i<(int)v.size(); i++) {
				auto it = find_if(begin(d), end(d), [&](int x) {
					return x % v[i].first == 0 && x % v[(i+1)%v.size()].first == 0;
				});

				if (it == end(d)) {
					cerr << x << '\n';
					return 0;
				}

				delims[i] = *it;
				d.erase(it);
			}

			for (int i=0; i<(int)v.size(); i++) {
				auto it = partition(begin(d), end(d), [&](int x) {
					return x % v[i].first == 0;
				});

				copy(begin(d), it, back_inserter(parts[i]));
				d.erase(begin(d), it);
			}

			for (int i=0; i<(int)v.size(); i++) {
				for (int x : parts[i]) cout << x << ' ';
				cout << delims[i] << ' ';
			}
			cout << "\n0\n";
		}
	}
}