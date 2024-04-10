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

	int n, x, y, c = 0;
	cin >> n >> x >> y;
	for (int i=0; i<n; i++) {
		int z;
		cin >> z;
		if (z <= x)
			c++;
	}
	if (x > y) {
		cout << n << '\n';
	} else {
		cout << (c+1) / 2 << '\n';
	}
}