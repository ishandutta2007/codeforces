#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, v;
vector<int> stepke, liftovi;

void solve() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	{
		int x, y;
		cin >> n >> m >> x >> y >> v;
		stepke.resize(x);
		liftovi.resize(y);
		for (int& x : stepke) {
			cin >> x;
		}
		for (int& x : liftovi) {
			cin >> x;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		if (x1 > x2) {
			swap(x1, x2);
		}
		if (y1 > y2) {
			swap(y1, y2);
		}

		int sol = 321321321;

		if (y1 == y2) {
			cout << x2 - x1 << '\n';
			continue;
		}

		// stepke
		{
			auto it = lower_bound(stepke.begin(), stepke.end(), x1);
			if (it != stepke.end() && *it <= x2) {
				sol = min(sol, x2 - x1 + y2 - y1);
			}

			// desno od x2
			it = upper_bound(stepke.begin(), stepke.end(), x2);
			if (it != stepke.end()) {
				sol = min(sol, y2 - y1 + *it - x1 + *it - x2);
			}

			// levo od x1
			it = lower_bound(stepke.begin(), stepke.end(), x1);
			if (it != stepke.begin()) {
				--it;
				sol = min(sol, y2 - y1 + x1 - *it + x2 - *it);
			}
		}

		// lift
		{
			int ydiff = (y2 - y1 + v - 1) / v;

			auto it = lower_bound(liftovi.begin(), liftovi.end(), x1);
			if (it != liftovi.end() && *it <= x2) {
				sol = min(sol, x2 - x1 + ydiff);
			}

			// desno od x2
			it = upper_bound(liftovi.begin(), liftovi.end(), x2);
			if (it != liftovi.end()) {
				sol = min(sol, ydiff + *it - x1 + *it - x2);
			}

			// levo od x1
			it = lower_bound(liftovi.begin(), liftovi.end(), x1);
			if (it != liftovi.begin()) {
				--it;
				sol = min(sol, ydiff + x1 - *it + x2 - *it);
			}
		}

		cout << sol << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}