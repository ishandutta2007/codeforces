#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

struct direction {
	ll x, y;
	int i, j;

	int kvadrant() const {
		if (x >= 0 && y >= 0)
			return 0;
		if (x <= 0 && y >= 0)
			return 1;
		if (x <= 0 && y <= 0)
			return 2;
		return 3;
	}

	bool operator< (const direction& other) const {
		int k1 = kvadrant();
		int k2 = other.kvadrant();

		if (k1 != k2)
			return k1 < k2;

		return det({0, 0}, {x, y}, {other.x, other.y}) > 0;
	}
};

struct marked_pt : pt {
	int id;
};

direction dirs[4000005];
int n, m;
ll s;
marked_pt a[2005];
int inv[2005];
pt glob1, glob2;

bool cmp(marked_pt a, marked_pt b) {
	return det(glob1, glob2, a) < det(glob1, glob2, b);
}

pt binarna_resenje;

bool binarna(pt u, pt v) {
	int l = 0, r = n-1;
	while (l <= r) {
		int m = (l+r) / 2;
		ll d = det(u, v, a[m]);
		if (d < s)
			l = m+1;
		else if (d > s)
			r = m-1;
		else {
			binarna_resenje = a[m];
			return true;
		}
	}
	return false;
}

void svopuj(int x, int y) {
	swap(a[inv[x]], a[inv[y]]);
	swap(inv[x], inv[y]);
}

void localsort(int x) {
	x = inv[x];

	while (x+1 < n && det(glob1, glob2, a[x]) > det(glob1, glob2, a[x+1])) {
		svopuj(a[x].id, a[x+1].id);
		x++;
	}

	while (x-1 >= 0 && det(glob1, glob2, a[x]) < det(glob1, glob2, a[x-1])) {
		svopuj(a[x].id, a[x-1].id);
		x--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;

	s *= 2;

	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (j != i)
				dirs[m++] = {a[j].x - a[i].x, a[j].y - a[i].y, i, j};

	sort(dirs, dirs+m);

	// sort po determinanti
	glob1 = a[dirs[0].i];
	glob2 = a[dirs[0].j];
	sort(a, a+n, cmp);

	for (int i=0; i<n; i++)
		inv[a[i].id] = i;

	for (int i=0; i<m; i++) {
		
		int ii = dirs[i].i;
		int jj = dirs[i].j;

		glob1 = a[inv[ii]];
		glob2 = a[inv[jj]];

		if (i > 0) {
			localsort(dirs[i-1].i);
			localsort(dirs[i-1].j);
		}
		localsort(jj);
		localsort(jj);

		if (binarna(a[inv[ii]], a[inv[jj]])) {
			cout << "Yes\n";
			cout << a[inv[ii]].x << ' ' << a[inv[ii]].y << '\n';
			cout << a[inv[jj]].x << ' ' << a[inv[jj]].y << '\n';
			cout << binarna_resenje.x << ' ' << binarna_resenje.y << '\n';
			return 0;
		}
	}

	cout << "No\n";
}