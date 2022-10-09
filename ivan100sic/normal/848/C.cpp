#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
int a[100005];

struct implicit_fenwick {
	unordered_map<int, long long> a;

	/* precondition: pos > 0 */
	void add(int pos, int val) {
		while (pos <= n) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	long long sum(int pos) {
		long long ret = 0;
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

struct fenwick {
	implicit_fenwick a[100005];

	void add(int x0, int y0, int val) {
		x0 = n + 1 - x0;

		// cerr << "Adding " << val << ' ' << " at " << x0 << ' ' << y0 << '\n';

		for (int x = x0; x < 100005; x += x & -x) {
			a[x].add(y0, val);
		}
	}

	// <= x, <= y
	long long sum(int x, int y) {
		x = n + 1 - x;

		// cerr << "Querying " << x << ' ' << y << '\n';

		long long ret = 0;
		while (x > 0) {
			ret += a[x].sum(y);
			x -= x & -x;
		}
		return ret;
	}
} drvo;

set<int> positions[100005];

void remove_val(int pos, int val) {
	auto it_begin = positions[val].begin();
	auto it_end = --positions[val].end();

	if (*it_begin == pos) {
		// skloni prvi ako postoji
		if (it_begin != it_end) {
			int x = *it_begin;
			int y = *next(it_begin);
			drvo.add(x, y, x-y);
		}
	} else if (*it_end == pos) {
		if (it_begin != it_end) {
			int x = *prev(it_end);
			int y = *it_end;
			drvo.add(x, y, x-y);
		}
	} else {
		// ima sa obe strane
		// izbaci dva, dodaj jedan
		auto it_center = positions[val].find(pos);
		int x = *prev(it_center);
		int y = pos;
		int z = *next(it_center);

		drvo.add(x, y, x-y);
		drvo.add(y, z, y-z);
		drvo.add(x, z, z-x);
	}

	positions[val].erase(pos);
}

void insert_val(int pos, int val) {
	positions[val].insert(pos);

	auto it_begin = positions[val].begin();
	auto it_end = --positions[val].end();

	if (*it_begin == pos) {
		// dodaj prvi ako postoji
		if (it_begin != it_end) {
			int x = *it_begin;
			int y = *next(it_begin);
			drvo.add(x, y, y-x);
		}
	} else if (*it_end == pos) {
		if (it_begin != it_end) {
			int x = *prev(it_end);
			int y = *it_end;
			drvo.add(x, y, y-x);
		}
	} else {
		// ima sa obe strane
		// dodaj dva, izbaci jedan
		auto it_center = positions[val].find(pos);
		int x = *prev(it_center);
		int y = pos;
		int z = *next(it_center);

		drvo.add(x, y, y-x);
		drvo.add(y, z, z-y);
		drvo.add(x, z, x-z);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		insert_val(i, a[i]);
	}

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			remove_val(x, a[x]);
			insert_val(x, y);
			a[x] = y;
		} else {
			cout << drvo.sum(x, y) << '\n';
		}
	}
	
}