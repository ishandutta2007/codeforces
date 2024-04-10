#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y
		- a.y*b.x - b.y*c.x - c.y*a.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pt a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	ll g = det(a, b, c);
	if (g > 0)
		cout << "LEFT\n";
	else if (g < 0)
		cout << "RIGHT\n";
	else
		cout << "TOWARDS\n";
}