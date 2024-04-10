#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	int id;

	bool operator== (const pt& o) const {
		return id == o.id;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y
		- a.y*b.x - b.y*c.x - c.y*a.x;
}

ll sp(pt a, pt b, pt c) {
	return (a.x-b.x)*(c.x-b.x) + (a.y-b.y)*(c.y-b.y);
}

bool naduzi(pt a, pt b, pt c) {
	return det(a, b, c) == 0 && sp(a, c, b) <= 0;
}

bool unutra(pt a, pt b, pt c, pt x) {
	int p = 0, m = 0;

	ll y;
	
	y = det(a, b, x);
	if (y < 0)
		m++;
	else if (y > 0)
		p++;

	y = det(b, c, x);
	if (y < 0)
		m++;
	else if (y > 0)
		p++;

	y = det(c, a, x);
	if (y < 0)
		m++;
	else if (y > 0)
		p++;

	return m == 3 || p == 3;
}

int n;
pt a[100005];

void resi(pt a, pt b, pt c) {
	if (rand() % 2)
		swap(a, b);
	if (rand() % 2)
		swap(b, c);

	// valjda je dovoljno random
	random_shuffle(::a, ::a+n);

	for (int j=0; j<n; j++) {
		pt x = ::a[j];

		if (x == a || x == b || x == c)
			continue;
		
		if (naduzi(a, b, x))
			resi(a, c, x);
		else if (naduzi(a, c, x))
			resi(a, b, x);
		else if (naduzi(b, c, x))
			resi(a, b, x);
		else if (unutra(a, b, c, x))
			resi(a, b, x);
	}

	cout << a.id << ' ' << b.id << ' ' << c.id << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i+1;
	}

	// nadji bilo koji trougao
	pt u = a[0];
	pt v = a[1];
	pt w;
	for (int i=2; i<n; i++)
		if (det(u, v, a[i]) != 0) {
			w = a[i];
			break;
		}

	resi(u, v, w);
}