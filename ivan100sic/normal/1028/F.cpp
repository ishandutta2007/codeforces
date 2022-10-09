#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

struct pt {
	int x, y;

	pt operator+ (const pt& b) const {
		return {x+b.x, y+b.y};
	}

	pt& operator+= (const pt& b) {
		x += b.x;
		y += b.y;
		return *this;
	}

	bool operator< (const pt& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}

	ll kvd() const {
		return x*1ll*x + y*1ll*y;
	}

	void reduce() {
		int g = gcd(x, y);
		x /= g;
		y /= g;
	}
};

map<pt, int> aux_cnt;
map<ll, set<pt>> pts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ajde da se nadamo da moze
	int q, tacaka = 0;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 3) {
			pt p = {x, y};
			p.reduce();
			cout << tacaka - aux_cnt[p] << '\n';
		} else if (t == 1) {
			tacaka++;
			pt p = {x, y};

			for (auto q : pts[p.kvd()]) {
				auto pq = p + q;
				pq.reduce();
				aux_cnt[pq] += 2;
			}

			pt q = p;
			q.reduce();
			aux_cnt[q] += 1;

			pts[p.kvd()].insert(p);

		} else {
			tacaka--;
			pt p = {x, y};
			
			pts[p.kvd()].erase(p);

			for (auto q : pts[p.kvd()]) {
				auto pq = p + q;
				pq.reduce();
				aux_cnt[pq] -= 2;
			}

			pt q = p;
			q.reduce();
			aux_cnt[q] -= 1;
		}
	}

}