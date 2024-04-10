#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <deque>
using namespace std;

int n, m, k;
int x[10005], y[10005];
vector<int> has_x[10005], has_y[10005];
int d[10005];

map<pair<int, int>, int> xyid;
deque<int> q;

void try0(int x, int y, int sugg) {
	int r = xyid[{x, y}];

	if (r) {
		// cerr << "guraj " << r << ' ' << sugg << '\n';
		if (sugg < d[r]) {
			d[r] = sugg;
			q.push_front(r);
		}
	}
}

void try1(int r, int sugg) {
	if (sugg < d[r]) {
		d[r] = sugg;
		q.push_back(r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	int start = 0;

	for (int i=1; i<=k; i++) {
		cin >> x[i] >> y[i];
		has_x[x[i]].push_back(i);
		has_y[y[i]].push_back(i);

		if (x[i] == 1 && y[i] == 1) {
			start = i;
		}

		xyid[{x[i], y[i]}] = i;
	}

	memset(d, 63, sizeof(d));
	d[start] = 0;

	q.push_back(start);

	while (!q.empty()) {
		int i = q.front(); q.pop_front();

		// cerr << "odradi " << i << '\n';

		int x = ::x[i];
		int y = ::y[i];
		int d = ::d[i];

		// potrazi susede, stavi ih napred
		try0(x+1, y, d);
		try0(x-1, y, d);
		try0(x, y+1, d);
		try0(x, y-1, d);

		// X

		if (x > 2) {
			for (int j : has_x[x-2]) {
				try1(j, d+1);
			}
		}

		if (x > 1) {
			for (int j : has_x[x-1]) {
				try1(j, d+1);
			}
		}

		if (x < n) {
			for (int j : has_x[x+1]) {
				try1(j, d+1);
			}
		}

		if (x < n-1) {
			for (int j : has_x[x+2]) {
				try1(j, d+1);
			}
		}

		// Y

		if (y > 2) {
			for (int j : has_y[y-2]) {
				try1(j, d+1);
			}
		}

		if (y > 1) {
			for (int j : has_y[y-1]) {
				try1(j, d+1);
			}
		}

		if (y < m) {
			for (int j : has_y[y+1]) {
				try1(j, d+1);
			}
		}

		if (y < m-1) {
			for (int j : has_y[y+2]) {
				try1(j, d+1);
			}
		}

		for (int j : has_x[x]) {
			try1(j, d+1);
		}

		for (int j : has_y[y]) {
			try1(j, d+1);
		}
	}

	int sol = 123123123;

	for (int i=1; i<=k; i++) {

		// cerr << i << ' ' << d[i] << '\n';

		if (x[i] == n && y[i] == m) {
			sol = min(sol, d[i]);
		} else if (x[i] >= n-1 || y[i] >= m-1) {
			sol = min(sol, d[i] + 1);
		}
	}

	if (sol > 12312312) {
		sol = -1;
	}

	cout << sol;

}