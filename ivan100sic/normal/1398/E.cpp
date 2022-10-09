// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct balanced_set {
	int k = 0;
	multiset<int> a, b;
	ll sa = 0;
	ll sb = 0;

	void operator-= (int x) {
		auto it = b.find(x);
		if (it != b.end()) {
			b.erase(it);
			sb -= x;
		} else {
			a.erase(a.find(x));
			sa -= x;
			if (b.size()) {
				int bb = *b.begin();
				a.insert(bb);
				sa += bb;
				sb -= bb;
				b.erase(b.begin());
			} else {
				k--;
			}
		}
	}

	void operator+= (int x) {
		if (k == 0) {
			b.insert(x);
			sb += x;
		} else {
			if (x <= *prev(a.end())) {
				int pa = *prev(a.end());
				b.insert(pa);
				a.erase(prev(a.end()));
				a.insert(x);
				sb += pa;
				sa -= pa;
				sa += x;
			} else {
				b.insert(x);
				sb += x;
			}
		}
	}

	void set_balance(int t) {
		while (k > t) {
			int pa = *prev(a.end());
			sb += pa;
			sa -= pa;
			b.insert(pa);
			a.erase(prev(a.end()));
			k--;
		}

		while (k < t) {
			int bb = *b.begin();
			a.insert(bb);
			b.erase(b.begin());
			sa += bb;
			sb -= bb;
			k++;
		}
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	balanced_set s0, s1, s;

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (y > 0) {
			(x ? s1 : s0) += y;
			s += y;
		} else {
			(x ? s1 : s0) -= -y;
			s -= -y;
		}

		int c0 = s0.a.size() + s0.b.size();
		int c1 = s1.a.size() + s1.b.size();

		// cerr << "set " << c0 << '\n';
		// cerr << s.sa << ' ' << s.sb << '\n';
		s.set_balance(c0);
		// cerr << s.sa << ' ' << s.sb << '\n';
		// da li su svi najveci ustvari tipa 1, i ima ih vise od 0
		ll ans;

		if (c1 && s.sb == s1.sb) {
			ans = s.sa + 2*s.sb - *s1.b.begin();
			// ako ima neko u s0 uzmi ga
			if (c0) {
				ans += *s0.b.rbegin();
			}
		} else {
			// prosto
			ans = s.sa + 2*s.sb;
		}

		cout << ans << '\n';
	}
}