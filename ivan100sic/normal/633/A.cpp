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

	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i <= c; i++) {
		int y = c - a * i;
		if (y % b == 0 && y >= 0) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}