// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, len, k;
int a[100005];

struct split {
	multiset<int> a, b;
	int t;
	ll as, bs;

	split(int t) : t(t), as(0), bs(0) {}

	void add(int x) {
		a.insert(x);
		as += x;
		if ((int)a.size() == t+1) {
			auto it = prev(a.end());
			as -= *it;
			bs += *it;
			b.insert(*it);
			a.erase(it);
		}
	}

	void rem(int x) {
		auto it = b.find(x);
		if (it != b.end()) {
			b.erase(it);
			bs -= x;
		} else {
			it = a.find(x);
			as -= x;
			a.erase(it);
			if ((int)a.size() == t-1 && b.size()) {
				int y = *b.begin();
				b.erase(b.begin());
				a.insert(y);
				as += y;
				bs -= y;
			}
		}
	}
};

ll resi() {
	split s(k);
	ll z = 0, sol = -1e18;

	auto add = [&](int x) {
		if (x < 0) {
			s.add(x);
		}
		z += x;
	};

	auto rem = [&](int x) {
		if (x < 0) {
			s.rem(x);
		}
		z -= x;
	};

	for (int i=0; i<len; i++) {
		add(a[i]);
	}

	for (int i=0; i+len<=n; i++) {
		sol = max(sol, z - 2 * s.as);
		if (i + len < n) {
			add(a[i+len]);
			rem(a[i]);
		}
	}

	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> len;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	cin >> k;

	ll sol = resi();
	for (int i=0; i<n; i++)
		a[i] *= -1;

	cout << max(sol, resi()) << '\n';
}