// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct pt {
	ld x, y;
};

ld det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

int n;
basic_string<pt> a;
ld b[1000005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));
	cout << setprecision(20) << fixed;

	cin >> n;
	ll z = 0;
	a.push_back({0, 0});
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z += x;
		pt b = {ld(i), ld(z)};
		while (a.size() >= 2 && det(a[a.size() - 2], a.back(), b) <= 0)
			a.pop_back();
		a += b;
	}

	int m = a.size();
	for (int i=1; i<m; i++) {
		for (int j=(int)a[i-1].x; j<(int)a[i].x; j++) {
			b[j] = (a[i].y - a[i-1].y) / (a[i].x - a[i-1].x);
		}
	}

	for (int i=0; i<n; i++)
		cout << b[i] << '\n';
}