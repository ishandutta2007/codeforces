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
};

int g[669];

struct node {
	map<int, int> e;
	int par = -1, len = 0;
};

vector<node> b(1);

int newnode(int par = -1, int len = 0) {
	b.push_back({{}, par, len});
	return b.size() - 1;
}

int walk(int x, int label, int amt) {
	while (amt > 0) {
		if (b[x].e.count(label)) {
			int z = b[x].e[label];
			int l = b[z].len;
			if (amt < l) {
				int y = newnode(x, amt);
				b[z].par = y;
				b[z].len -= amt;
				b[x].e[label] = y;
				b[y].e[label] = z;
				return y;
			} else {
				x = z;
				amt -= l;
			}
		} else {
			int y = newnode(x, amt);
			b[x].e[label] = y;
			return y;
		}
	}
	return x;
}

int tgt[5005];

void build() {
	b.reserve(500000);
	sieve s(5005);
	for (int x=1; x<=5000; x++) {
		auto v = s.factor_small(x);
		for (auto [p, c] : v) {
			p = lower_bound(begin(s.primes), end(s.primes), p) - begin(s.primes);
			g[p] += c;
			int t = 0;
			for (int i=668; i>=0; i--) {
				t = walk(t, i, g[i]);
			}
			tgt[x] = t;
		}
	}
}

int c[500000], s[500000];

ll dfs1(int x) {
	s[x] = c[x];
	ll r = 0;
	for (auto [_, y] : b[x].e) {
		ll t = dfs1(y);
		r += t + s[y] * 1ll * b[y].len;
		s[x] += s[y];
	}
	return r;
}

ll dfs2(int x, ll q) {
	ll r = q;
	for (auto [_, y] : b[x].e)
		r = min(r, dfs2(y, q + b[y].len*(s[0] - 2ll*s[y])));
	return r;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	build();
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		c[tgt[x]]++;
	}

	cout << dfs2(0, dfs1(0)) << '\n';
}