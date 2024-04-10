#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll a, b, i;
	bool operator< (const pt& o) const {
		if (a - b != o.a - o.b) {
			return a - b > o.a - o.b;
		}
		return i < o.i;
	}
};

struct lepotan {
	const int limit;
	set<pt> donji, gornji;

	ll sum_donji, sum_gornji;

	lepotan(int limit) : limit(limit),
		sum_donji(0), sum_gornji(0) {}

	void ubaci(ll a, ll b, ll id) {
		donji.insert({ a, b, id });
		sum_donji += max(a, b);
		if ((int)donji.size() > limit) {
			auto p = *--donji.end();
			donji.erase(--donji.end());
			sum_donji -= max(p.a, p.b);
			gornji.insert(p);
			sum_gornji += p.b;
		}
	}

	void brisi(ll a, ll b, ll id) {
		if (gornji.count({ a, b, id })) {
			gornji.erase({ a, b, id });
			sum_gornji -= b;
		}
		else if (donji.count({ a, b, id })) {
			donji.erase({ a, b, id });
			sum_donji -= max(a, b);
			if (gornji.size()) {
				auto p = *gornji.begin();
				gornji.erase(gornji.begin());
				sum_gornji -= p.b;
				donji.insert(p);
				sum_donji += max(p.a, p.b);
			}
		}
	}

	ll suma() {
		return sum_donji + sum_gornji;
	}
};

int n, x, y;
ll a[200005], b[200005];

void solve() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	lepotan e(y);

	for (int i = 0; i < n; i++) {
		e.ubaci(a[i], b[i], i);
	}

	ll sol = e.suma();

	for (int i = 0; i < n; i++) {
		e.brisi(a[i], b[i], i);
		e.ubaci(a[i] << x, b[i], i);
		sol = max(sol, e.suma());
		e.brisi(a[i] << x, b[i], i);
		e.ubaci(a[i], b[i], i);
	}

	cout << sol << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}