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

	ll x, y, c = 0;
	cin >> x >> y;
	while (x <= y) {
		x *= 3;
		y *= 2;
		c++;
	}

	cout << c << '\n';
}