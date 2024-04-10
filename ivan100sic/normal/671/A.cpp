#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	int id;

	ld a, b, t, p, q;
};

bool cmp1(pt a, pt b) {
	return a.p < b.p;
}

bool cmp2(pt a, pt b) {
	return a.q < b.q;
}

ll sq(ll x) {
	return x*x;
}

ld dist(pt a, pt b) {
	return sqrt((ld)sq(a.x-b.x) + sq(a.y-b.y));
}

pt a, b, t;
pt c[100005];
pt d[100005];
ld sol;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> c[i].x >> c[i].y;
		c[i].id = i;
		c[i].a = dist(a, c[i]);
		c[i].b = dist(b, c[i]);
		c[i].t = dist(t, c[i]);
		c[i].p = c[i].a - c[i].t;
		c[i].q = c[i].b - c[i].t;
		sol += c[i].t;
		sol += c[i].t;
	}

	copy(c, c+n, d);
	sort(c, c+n, cmp1);
	sort(d, d+n, cmp2);

	ld extra = 1e50;

	int h = min(10, n);

	for (int i=0; i<h; i++)
		for (int j=0; j<h; j++) {
			if (c[i].id == d[j].id)
				continue;
			extra = min(extra, c[i].p + d[j].q);
		}

	// samo a
	for (int i=0; i<n; i++)
		extra = min(extra, c[i].p);

	// samo b
	for (int j=0; j<n; j++)
		extra = min(extra, d[j].q);

	cout.precision(20);
	cout << fixed;
	cout << sol + extra << "\n";
}