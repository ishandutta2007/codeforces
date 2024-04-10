#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ld x, y;
	basic_string<int> id;
	bool operator< (pt b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

bool ispod(pt a, pt b) {
	// cerr << "ispod: " << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << '\n';
	return a.x <= b.x && a.y <= b.y;
}

ld det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

int n, nn, m, h;
pt a[200005], b[200005], c[200005];
map<pair<int, int>, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		if (mp.count({x, y}))
			a[mp[{x, y}]].id += i;
		else {
			a[nn].x = (ld)1 / x;
			a[nn].y = (ld)1 / y;
			a[nn].id = {i};
			mp[{x, y}] = nn;
			nn++;
		}
	}
	sort(a, a+nn);
	for (int i=0; i<nn; i++) {
		// cerr << a[i].x << ' ' << a[i].y << '\n';
		while (h >= 2 && det(c[h-2], c[h-1], a[i]) < -1e-16)
			h--;
		c[h++] = a[i];
	}

	{
		basic_string<int> sol;
		for (int i=0; i<h; i++)
			sol += c[i].id;
		sort(sol.begin(), sol.end());
		for (int x : sol)
			cerr << x << ' ';
		cerr << '\n';
	}

	// odbaci visak
	while (h >= 2 && ispod(c[h-2], c[h-1]))
		h--;

	basic_string<int> sol;
	for (int i=0; i<h; i++)
		sol += c[i].id;
	sort(sol.begin(), sol.end());
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}