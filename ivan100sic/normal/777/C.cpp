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

int n, m;
vector<vector<int>> a;

struct yis_sorted {
	deque<int> q;
	deque<int> good;

	int tot;

	yis_sorted() : tot(0) {}

	void add(int x) {
		if (q.size() == 0) {
			q.push_back(x);
			good.push_back(1);
			tot = 1;
		} else {
			int g = (x >= *q.rbegin()) ? 1 : 0;
			good.push_back(g);
			q.push_back(x);
			tot += g;
		}
	}

	bool operator() () {
		return tot == q.size();
	}

	void remove() {
		tot -= *good.begin();
		good.pop_front();
		q.pop_front();

		if (good.size() >= 1) {
			tot -= *good.begin();
			good.pop_front();
			good.push_front(1);
			tot += 1;
		}		
	}

	void undo() {
		tot -= *good.rbegin();
		good.pop_back();
		q.pop_back();
	}

};

int rr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	a.resize(n+1, vector<int>(m+1));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}

	vector<yis_sorted> hehe(m+1);

	int r = 0;
	for (int l=1; l<=n; l++) {
		while (1) {
			if (r == n) {
				break;
			}

			// dodaj
			for (int j=1; j<=m; j++) {
				hehe[j].add(a[r+1][j]);
			}

			bool ok = false;
			for (int j=1; j<=m; j++) {
				ok |= hehe[j]();
				// cerr << hehe[j]() ? "1 " : "0 ";
			}
			// cerr << '\n';

			if (!ok) {
				// we fucced up
				for (int j=1; j<=m; j++) {
					hehe[j].undo();
				}

				break;
			} else {
				r++;
			}
		}

		rr[l] = r;
		cerr << l << ' ' << r << '\n';
		for (int j=1; j<=m; j++) {
			hehe[j].remove();
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (r <= rr[l]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}