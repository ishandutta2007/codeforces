// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998244353;
typedef modint<mod> mint;

template<class T = mint>
struct binomial {
	vector<T> f, finv;

	binomial(int n) : f(n), finv(n) {
		f[0] = finv[0] = 1;
		for (int i=1; i<n; i++) {
			f[i] = f[i-1] * i;
			finv[i] = f[i].inv();
		}
	}

	mint mix(int a, int b) {
		if (a < 0 || b < 0)
			return 0;
		return f[a+b] * finv[a] * finv[b];
	}

	mint choose(int n, int k) {
		return mix(n-k, k);
	}
};

namespace g {
	int u[20], v[20], m;
}

int n;
int l[300005], r[300005], z[300005];
int u[40], k;
ll adj[40];

int sos[1 << 20][21];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> g::m;

	binomial bin(n+1);

	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
		z[l[i]]++;
		z[r[i]+1]--;
	}

	for (int i=1; i<=n; i++) {
		z[i] += z[i-1];
	}

	for (int i=0; i<g::m; i++) {
		cin >> g::u[i] >> g::v[i];
		u[k++] = --g::u[i];
		u[k++] = --g::v[i];
	}

	sort(u, u+k);
	k = unique(u, u+k) - u;

	for (int i=0; i<g::m; i++) {
		int x = lower_bound(u, u+k, g::u[i]) - u;
		int y = lower_bound(u, u+k, g::v[i]) - u;
		adj[x] |= 1ll << y;
		adj[y] |= 1ll << x;
	}

	int h = k >> 1;
	for (int mask=0; mask<(1<<h); mask++) {
		bool ok = 1;
		for (int i=0; i<h; i++) {
			if ((mask & (1 << i)) && (adj[i] & mask)) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			sos[mask][__builtin_popcount(mask)] += 1;
		}
	}

	for (int ax=1; ax<(1<<h); ax<<=1) {
		for (int mask=0; mask<(1<<h); mask++) {
			if (!(mask & ax)) {
				for (int s=0; s<=h; s++) {
					sos[mask | ax][s] += sos[mask][s];
				}
			}
		}
	}

	map<ll, vector<ll>> cache;
	mint sol = 0;

	for (int s=1; s<=n; s++) {
		ll mask = 0;
		for (int i=0; i<k; i++) {
			if (l[u[i]] <= s && s <= r[u[i]]) {
				mask |= 1ll << i;
			}
		}
		int pcm = __builtin_popcountll(mask);

		vector<ll>& ways = cache[mask];
		if (!ways.size()) {
			ways.resize(k+1);
			ll hmask = mask & ((1ll << k) - (1ll << h));
			ll lmask = mask & ((1ll << h) - 1);

			auto job = [&](ll hsmask) {
				ll lcan = lmask;
				for (int i=h; i<k; i++) {
					if (hsmask & (1ll << i)) {
						if (hsmask & adj[i]) {
							return;
						}
						lcan &= ~adj[i];
					}
				}
				int pc = __builtin_popcountll(hsmask);
				for (int j=0; j<=h; j++) {
					ways[j + pc] += sos[lcan][j];
				}
			};

			for (ll curr = hmask; curr; curr = hmask & (curr-1)) {
				job(curr);
			}
			job(0);
		}

		for (int j=0; j<=k; j++) {
			mint bc = bin.choose(z[s]-pcm, s-j);
			sol += bc * ways[j];
		}
	}

	cout << sol() << '\n';
}