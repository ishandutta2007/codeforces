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

	int x, y, rf = 0;
	cin >> x >> y;
	for (int r=0; r*r<=x*x+y*y; r++) {
		if (r*r == x*x + y*y) {
			cout << "black\n";
			return 0;
		}
		rf = r;
	}
	int c = 0;
	if ((x < 0) != (y < 0))
		c = 1;
	c ^= rf % 2;
	cout << (c ? "white\n" : "black\n");
}