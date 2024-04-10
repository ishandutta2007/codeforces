#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n;
int a[35];

set<pair<int, int>> mark;

// udesno
pair<int, int> dirs[8] = {
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1}
};

struct mover {
	int x, y, dx, dy;

	mover() : x(0), y(0), dx(0), dy(1) {}

	long long hash() const {
		return x * 1000000000000ll + y * 1000000000ll +
		dx * 1000000ll + dy * 1000ll;
	}

	bool operator< (const mover& other) const {
		return hash() < other.hash();
	}

	bool operator== (const mover& other) const {
		return hash() == other.hash();
	}

	void move() {
		x += dx;
		y += dy;
		mark.insert({x, y});
	}

	void rright() {
		for (int i=0; i<8; i++) {
			if (dirs[i].first == dx && dirs[i].second == dy) {
				dx = dirs[(i+1)&7].first;
				dy = dirs[(i+1)&7].second;
				return;
			}
		}
	}

	void rleft() {
		for (int i=0; i<8; i++) {
			if (dirs[i].first == dx && dirs[i].second == dy) {
				dx = dirs[(i+7)&7].first;
				dy = dirs[(i+7)&7].second;
				return;
			}
		}
	}

	pair<mover, mover> fork() {
		mover a, b;
		a = *this;
		b = *this;
		a.rleft();
		b.rright();
		return {a, b};
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	mark.insert({0, 0});

	a[1]--;

	vector<mover> p(1);

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=a[i]; j++) {
			for (mover& m : p) {
				m.move();
			}
		}

		vector<mover> q;

		for (mover& m : p) {
			auto ab = m.fork();
			q.push_back(ab.first);
			q.push_back(ab.second);
		}

		sort(q.begin(), q.end());
		q.resize(unique(q.begin(), q.end()) - q.begin());

		p = q;
	}

	cout << mark.size();
}