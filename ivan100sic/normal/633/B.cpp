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

int f(int x) {
	int z = 0;
	while (x) {
		x /= 5;
		z += x;
	}
	return z;
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m;
	cin >> m;

	vector<int> sol;
	for (int i = 1; i <= 10 * m; i++) {
		if (f(i) == m) {
			sol.push_back(i);
		}
	}

	cout << sol.size() << '\n';
	for (int x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}