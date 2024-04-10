#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <iterator>
using namespace std;

typedef list<int>::iterator lii;

int list_pos(list<int>& u, lii v) {
	int c = 1;
	while (v != u.begin()) {
		--v;
		++c;
	}
	return c;
}

int main() {
	int n, k;
	vector<int> b;
	list<int> a;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cin >> k;
	b.resize(k);
	for (int& x : b) {
		cin >> x;
	}

	// cerr << "input read\n";

	int j = 0, sum = 0, lo=999999999, hi=-1;

	vector<pair<lii, lii>> poss;
	auto state = a.begin();

	for (auto it = a.begin(); it != a.end(); it++) {
		int x = *it;
		sum += x;
		lo = min(lo, x);
		hi = max(hi, x);
		if (sum >= b[j]) {
			if (sum > b[j]) {
				cout << "NO";
				return 0;
			}
			sum = 0;
			if (lo == hi && !(state == it)) {
				cout << "NO";
				return 0;
			}
			poss.push_back({state, next(it)});
			state = next(it);
			j++;
			lo = 999999999;
			hi = -1;
		}
	}

	if (j != k || sum != 0) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";

	for (auto p : poss) {
		int steps = list_pos(a, p.second) - list_pos(a, p.first) - 1;
		// cerr << "doing " << steps << " steps\n";		
		auto mit = p.first;

		auto power_level = [&](lii it) {
			int r = 0;
			if (it != p.first) {
				if (*it > *prev(it)) {
					r++;
				}
			}
			if (next(it) != p.second) {
				if (*it > *next(it)) {
					r++;
				}
			}
			return r;
		};

		for (auto it = p.first; it != p.second; ++it) {
			if (*it > *mit) {
				mit = it;
			} else if (*it == *mit && power_level(it) > power_level(mit)) {
				mit = it;
			}
		}

		while (steps > 0) {
			if (mit == p.first) {
				*mit += *next(mit);
				cout << list_pos(a, mit) << " R\n";
				a.erase(next(mit));
			} else if (next(mit) == p.second) {
				*mit += *prev(mit);
				cout << list_pos(a, mit) << " L\n";
				if (prev(mit) == p.first) {
					p.first = mit;
				}
				a.erase(prev(mit));
			} else if (*mit > *next(mit)) {
				*mit += *next(mit);
				cout << list_pos(a, mit) << " R\n";
				a.erase(next(mit));
			} else if (*mit > *prev(mit)) {
				*mit += *prev(mit);
				cout << list_pos(a, mit) << " L\n";
				if (prev(mit) == p.first) {
					p.first = mit;
				}
				a.erase(prev(mit));
			} else {
				return 1;
			}
			steps--;
		}
	}
}