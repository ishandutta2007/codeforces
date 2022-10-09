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

int n, w, h;

struct dancer {
	int x0, y0, t, lvl, id, raz;

	bool operator< (const dancer& other) const {
		return lvl < other.lvl;
	}

} a[100005], b[100005];

bool cmp_raz(dancer x, dancer y) {
	return x.raz < y.raz;
}

pair<int, int> sol[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w >> h;
	for (int i=1; i<=n; i++) {
		int g, p, t;
		cin >> g >> p >> t;
		if (g == 1) {
			a[i].x0 = p;
			a[i].y0 = 0;
		} else {
			a[i].x0 = 0;
			a[i].y0 = p;
		}
		a[i].t = t;
		a[i].id = i;
		a[i].lvl = a[i].x0 + a[i].y0 - t;
		a[i].raz = a[i].x0 - a[i].y0;
	}

	sort(a+1, a+n+1);
	copy(a+1, a+n+1, b+1);

	// jednake grupe sortiraj po razlici

	

	int l = 1;
	for (int r=1; r<=n+1; r++) {
		if (r > n || a[l] < a[r]) {
			// cerr << "srange " << l << ' ' << r << '\n';

			for (int i=l; i<r; i++) {
				if (a[i].x0 == 0) {
					a[i].x0 = w;
				} else {
					a[i].y0 = h;
				}
				a[i].raz = a[i].x0 - a[i].y0;
			}
			
			sort(a+l, a+r, cmp_raz);
			sort(b+l, b+r, cmp_raz);

			//for (int i=l; i<r; i++) {
			//	cerr << a[i].x0 << ' ' << a[i].y0 << '\n';
			//}

			for (int i=l; i<r; i++) {
				b[i].x0 = a[i].x0;
				b[i].y0 = a[i].y0;
			}
			l = r;
		}
	}

	

	for (int i=1; i<=n; i++) {
		sol[b[i].id] = {b[i].x0, b[i].y0};
	}

	for (int i=1; i<=n; i++) {
		cout << sol[i].first << ' ' << sol[i].second << '\n';
	}

}