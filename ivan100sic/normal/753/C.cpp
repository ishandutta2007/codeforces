#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> ok;

bool done = false;

pair<int, int> guess(int x) {
	char s[5];
	for (int i=0; i<4; i++) {
		s[i] = x % 10 + '0';
		x /= 10;
	}
	s[4] = 0;
	cout << s << '\n' << flush;
	int a, b;
	cin >> a >> b;
	if (a == 4) {
		done = true;
	}
	return {a, b};
}

bool perm(int x) {
	int c[10] = {0};
	for (int i=0; i<4; i++) {
		c[x % 10]++;
		x /= 10;
	}
	return *max_element(c, c+10) == 1;
}

pair<int, int> cross(int x, int y) {
	int c[10] = {0}, d[10] = {0}, e = 0, f = 0;

	for (int i=0; i<4; i++) {
		c[x % 10]++;
		d[y % 10]++;
		if (x % 10 == y % 10) {
			e++;
		}
		x /= 10;
		y /= 10;
	}

	for (int i=0; i<10; i++) {
		f += min(c[i], d[i]);
	}
	return {e, f-e};
}

vector<pair<int, int>> crs = {
	{0, 0},
	{0, 1},
	{0, 2},
	{0, 3},
	{0, 4},
	{1, 0},
	{1, 2},
	{1, 3},
	{2, 0},
	{2, 1},
	{2, 2},
	{3, 0},
	{4, 0}
};

map<pair<int, int>, int> eliminate_smart(const vector<int>& ok, int x) {
	map<pair<int, int>, int> mp;
	for (int y : ok) {
		mp[cross(x, y)]++;
	}
	return mp;
}

int find_move() {
	int opt = 10000;
	int xx = 0;
	for (int q=0; q<10000; q++) {
		// za ovaj upit, pogledaj sta se desava
		auto mp = eliminate_smart(ok, q);

		int badness = 0;
		for (auto p : mp) {
			badness = max(badness, p.second);
		}

		if (badness < opt) {
			opt = badness;
			xx = q;
		}
	}
	return xx;
}

vector<int> eliminate(const vector<int>& ok, int x, pair<int, int> res) {
	vector<int> a;
	for (int y : ok) {
		if (cross(x, y) == res) {
			a.push_back(y);
		}
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<10000; i++) {
		if (perm(i)) {
			ok.push_back(i);
		}
	}

	ok = eliminate(ok, 3210, guess(3210));
	ok = eliminate(ok, 6541, guess(6541));

	while (ok.size() > 1) {
		int x = find_move();
		ok = eliminate(ok, x, guess(x));
	}

	if (!done) {
		guess(ok[0]);
	}	
}