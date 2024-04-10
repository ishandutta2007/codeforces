#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
map<long long, int> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		long long x;
		cin >> x;
		if (__builtin_popcountll(x) > 1) {
			while (__builtin_popcountll(x) > 1) {
				x -= x & -x;
			}
			x += 1;
		}
		c[x]++;
	}

	vector<int> sols;

	if (c[1] == 0) {
		cout << -1;
		return 0;
	}

	int lo = (c[1] + 1) / 2;
	int hi = c[1];

	for (int k=lo; k<=hi; k++) {
		map<long long, int> stops_count;
		int open = k;
		long long expected_val = 1;
		bool bad = false;

		vector<pair<long long, int>> extra;

		for (auto p : c) {
			if (__builtin_popcountll(p.first) == 1) {
				if (p.first != expected_val) {
					bad = true;
					break;
				}
				expected_val *= 2;

				// cerr << "open = " << open << ", x = " << p.second << '\n';

				int x = p.second;
				if (x < open) {
					stops_count[p.first] = open - x;
					open = x;
				} else if (open < x && x <= 2*open) {
					extra.push_back({p.first, x - open});
				} else if (x == open) {
					// do nothing
				} else {
					bad = true;
					break;
				}
			} else {
				extra.push_back(p);
			}
		}

		stops_count[expected_val] = open;

		// debug
		/*
		for (auto p : stops_count) {
			cerr << "stops_count " << p.first << ' ' << p.second << '\n';
		}
		for (auto p : extra) {
			cerr << "extra " << p.first << ' ' << p.second << '\n';
		}
		*/
		
		
		auto it = stops_count.begin();
		for (auto p : extra) {
			int amount = p.second;
			long long val = p.first;

			while (amount > 0) {
				if (it == stops_count.end()) {
					bad = true;
					break;
				}
				if (val >= it->first) {
					++it;
					continue;
				}
				int decr = min(amount, it->second);

				//cerr << "matched: " << val << ' ' << it->first << ' ' << decr << '\n';

				amount -= decr;
				it->second -= decr;
				if (it->second == 0) {
					++it;
				}
			}
		}

		if (!bad) {
			sols.push_back(k);
		}
	}

	if (sols.size() == 0) {
		cout << -1;
		return 0;
	}

	for (int x : sols) {
		cout << x << ' ';
	}
}