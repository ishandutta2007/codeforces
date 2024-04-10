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
int x1, y1, x2, y2;

vector<double> ulaz, izlaz;

struct rac {
	long long p, q;

	rac(long long pp, long long qq) : p(pp), q(qq) {
		if (q < 0) {
			q = -q;
			p = -p;
		}
	}

	bool operator< (const rac& other) const {
		return p * other.q < q * other.p;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x1 >> y1 >> x2 >> y2;

	rac tl(0, 1), tr(2e12, 1);

	for (int i=1; i<=n; i++) {
		int x, y, vx, vy;
		cin >> x >> y >> vx >> vy;		

		if (vx == 0) {
			if (x <= x1 || x >= x2) {
				tr = rac(0, 1);
				tl = rac(1, 1);
			}
		} else {
			rac t1(x1 - x, vx);
			rac t2(x2 - x, vx);

			rac ttl = min(t1, t2);
			rac ttr = max(t1, t2);

			tl = max(tl, ttl);
			tr = min(tr, ttr);
		}

		// y

		if (vy == 0) {
			if (y <= y1 || y >= y2) {
				tr = rac(0, 1);
				tl = rac(1, 1);
			}
		} else {
			rac t1(y1 - y, vy);
			rac t2(y2 - y, vy);

			rac ttl = min(t1, t2);
			rac ttr = max(t1, t2);

			tl = max(tl, ttl);
			tr = min(tr, ttr);
		}
	}

	cout.precision(20);

	if (tl < tr) {
		cout << fixed << (double)tl.p / tl.q;
	} else {
		cout << -1;
	}

}