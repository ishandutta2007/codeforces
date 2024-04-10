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

	int x, y;
	cin >> x >> y;
	int z = -1;
	if (y % x == 0) {
		y /= x, z++;
		while (y % 3 == 0)
			y /= 3, z++;
		while (y % 2 == 0)
			y /= 2, z++;
		if (y != 1)
			z = -1;
	}
	cout << z << '\n';
}