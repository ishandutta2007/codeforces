#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// O -> OOC
	// C -> CCC
	// 0 1

	int x, y;
	cin >> x >> y;

	if (x % 2 != y % 2 && x+1 >= y && y > 0 && (y != 1 || x == 0)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}