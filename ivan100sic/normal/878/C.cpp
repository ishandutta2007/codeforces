#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<pair<int, int>> vpii;

int n, m;

multiset<pair<vpii, int>> s;

vpii spoji(vpii a, vpii b) {
	bool c = false, d = false;
	for (int i=0; i<m; i++) {
		c |= a[i].second > b[i].first;
		d |= b[i].second > a[i].first;
	}
	if (c && d) {
		for (int i=0; i<m; i++) {
			a[i].first = min(a[i].first, b[i].first);
			a[i].second = max(a[i].second, b[i].second);
		}
	}
	return a;
}

void add(vector<pair<int, int>> v) {
	auto it = s.insert({v, 1});
	while (1) {
		bool smth = false;
		if (it != s.begin()) {
			auto w = spoji(it->first, prev(it)->first);
			if (w != it->first) {
				int c = it->second + prev(it)->second;
				s.erase(prev(it));
				s.erase(it);
				it = s.insert({w, c});
				smth = true;
			}
		}

		if (next(it) != s.end()) {
			auto w = spoji(it->first, next(it)->first);
			if (w != it->first) {
				int c = it->second + next(it)->second;
				s.erase(next(it));
				s.erase(it);
				it = s.insert({w, c});
				smth = true;
			}
		}

		if (!smth)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		vpii v(m);
		for (auto& [x, y] : v) {
			cin >> x;
			y = x;
		}
		add(v);
		cout << prev(s.end())->second << '\n';
	}
}