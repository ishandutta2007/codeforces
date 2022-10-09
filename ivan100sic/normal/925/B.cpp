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

pair<int, int> a[300005];
int n, x, y;

void resi(int x, int y, bool naopako) {
	int z = 0, j = -1, k = -1, c = 0;

	// zadovolji x

	for (int i = 1; i <= n; i++) {
		z = a[i].first;
		c++;
		if (j == -1 && z * c >= x) {
			j = i;
			z = c = 0;
		}
		if (j != -1 && k == -1 && z * c >= y) {
			k = i;
			break;
		}
	}
	if (k != -1) {
		cout << "Yes\n";
		if (!naopako) {
			cout << j << ' ' << k - j << '\n';
			for (int i = 1; i <= j; i++) {
				cout << a[i].second << ' ';
			}
			cout << '\n';
			for (int i = j + 1; i <= k; i++) {
				cout << a[i].second << ' ';
			}
			cout << '\n';
		}
		else {
			cerr << "naopako!\n";
			cout << k - j << ' ' << j << '\n';
			for (int i = j + 1; i <= k; i++) {
				cout << a[i].second << ' ';
			}
			cout << '\n';
			for (int i = 1; i <= j; i++) {
				cout << a[i].second << ' ';
			}
			cout << '\n';
		}
		
		exit(0);
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);

	resi(x, y, false);
	resi(y, x, true);

	cout << "No\n";
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}