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

int n;
pt a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<=n; i++)
		cin >> a[i].x >> a[i].y;
	a[n] = a[0];
	a[n+1] = a[1];

	int z = 0;

	for (int i=0; i<n; i++) {
		if (det(a[i], a[i+1], a[i+2]) > 0)
			z++;
	}

	cout << z << '\n';
}