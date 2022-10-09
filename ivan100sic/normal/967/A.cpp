#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, s;
	cin >> n >> s;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x = 60 * x + y;
		a.push_back(x);
	}

	if (a[0] > s) {
		cout << "0 0\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1 || a[i + 1] - a[i] > 2*s + 1) {
			cout << (a[i] + s + 1) / 60 << ' ' << (a[i] + s + 1) % 60 << '\n';
			return;
		}
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}