// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

set<int> s;
multiset<int> diff;

void dod(int x) {
	auto it = s.insert(x).first;
	if (it != s.begin() && next(it) != s.end()) {
		diff.erase(diff.find(*next(it) - *prev(it)));
	}
	if (it != s.begin()) {
		diff.insert(x - *prev(it));
	}
	if (next(it) != s.end()) {
		diff.insert(*next(it) - x);
	}
}

void rem(int x) {
	auto it = s.find(x);
	if (it != s.begin() && next(it) != s.end()) {
		diff.insert(*next(it) - *prev(it));
	}
	if (it != s.begin()) {
		diff.erase(diff.find(x - *prev(it)));
	}
	if (next(it) != s.end()) {
		diff.erase(diff.find(*next(it) - x));
	}
	s.erase(it);
}

int ans() {
	if (s.size() <= 1) return 0;
	return *s.rbegin() - *s.begin() - *diff.rbegin();
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, q;
	cin >> n >> q;
	while (n--) {
		int x;
		cin >> x;
		dod(x);
	}

	cout << ans() << '\n';

	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t) dod(x);
		else rem(x);
		cout << ans() << '\n';
	}
}