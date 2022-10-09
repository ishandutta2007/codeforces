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

struct lex {
	int c[65];

	void reset() {
		for (int i=0; i<65; i++) {
			c[i] = 0;
		}
	}

	void add(int i) {
		c[i] = 1;
	}

	int get() {
		for (int i=0; i<65; i++) {
			if (c[i] == 0) {
				return i;
			}
		}
	}
};

typedef unsigned long long ull;

map<pair<int, ull>, int> nimber;

int calc_nimber(int x, ull banned) {

	if (x == 0) {
		return 0;
	}

	auto it = nimber.find({x, banned});
	if (it != nimber.end()) {
		return it->second;
	}


	int& nb = nimber[{x, banned}];

	lex lx;
	lx.reset();

	for (int i=1; i<=x; i++) {
		if ((banned & (1ll<<i)) == 0) {
			// ok potez
			int t = calc_nimber(x-i, banned | (1ll << i));

			lx.add(t);
		}
	}

	nb = lx.get();

	return nb;
}

int cool[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5,
	5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10,
	10, 10, 10, 10};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	/*

	for (int i=1; i<=60; i++) {
		calc_nimber(i, 0);
		cerr << i << '\n';
	}

	for (int i=1; i<=60; i++) {
		cout << nimber[{i, 0}] << ", ";
	}

	return 0;
	*/
	
	int n;
	cin >> n;
	int x = 0;
	while (n--) {
		int y;
		cin >> y;
		x ^= cool[y];
	}

	cout << (x ? "NO" : "YES");
}