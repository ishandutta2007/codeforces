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

ll a[6];
pt b[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<6; i++)
		cin >> a[i];

	b[0] = {0, 0};
	b[1] = {a[0], a[0]};
	b[2] = {a[0] + 2*a[1], a[0]};
	b[3] = {a[0] + 2*a[1] + a[2], a[0] - a[2]};
	b[4] = {a[0] + 2*a[1] + a[2] - a[3], a[0] - a[2] - a[3]};
	b[5] = {a[0] + 2*a[1] + a[2] - a[3] - 2*a[4], a[0] - a[2] - a[3]};

	b[6] = b[0];
	ll c = 0;
	for (int i=0; i<6; i++)
		c += det({0, 0}, b[i], b[i+1]);
	c = abs(c);
	cout << c/2 << '\n';
}