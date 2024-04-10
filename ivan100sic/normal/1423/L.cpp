// Retired?
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct bs {
	array<ull, 16> a;

	bs() {
		fill(begin(a), end(a), 0);
	}

	bool operator< (const bs& o) const {
		return a < o.a;
	}

	void set(int x) {
		a[x >> 6] |= 1ull << (x & 63);
	}

	void operator^= (const bs& o) {
		for (int i=0; i<16; i++) a[i] ^= o.a[i];
	}
};

int n, s, d, sl, sr;

bs a[30], l[1 << 11], r[1 << 19];
map<bs, int> mp;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> s >> d;

	for (int i=0; i<s; i++) {
		int c;
		cin >> c;
		while (c--) {
			int x;
			cin >> x;
			x--;
			a[i].set(x);
		}
	}

	sl = s * 11 / 30;
	sr = s - sl;

	for (int mask=0; mask<(1<<sl); mask++) {
		for (int i=0; i<sl; i++) {
			if (mask & (1 << i)) {
				l[mask] ^= a[i];
			}
		}
	}

	for (int mask=0; mask<(1<<sr); mask++) {
		for (int i=0; i<sr; i++) {
			if (mask & (1 << i)) {
				r[mask] ^= a[i + sl];
			}
		}
	}

	for (int mask=0; mask<(1<<sr); mask++) {
		auto it = mp.find(r[mask]);
		if (it == mp.end()) {
			mp[r[mask]] = __builtin_popcount(mask);
		} else {
			auto& v = mp[r[mask]];
			v = min(v, __builtin_popcount(mask));
		}
	}

	while (d--) {
		bs a;
		int t, sol = 123123123;
		cin >> t;
		while (t--) {
			int x;
			cin >> x;
			a.set(x-1);
		}

		for (int i=0; i<(1<<sl); i++) {
			auto b = a;
			b ^= l[i];

			int pc = __builtin_popcount(i);

			auto it = mp.find(b);
			if (it != mp.end()) {
				sol = min(sol, pc + it->second);
			}
		}

		cout << (sol > 123123 ? -1 : sol) << '\n';
	}
}