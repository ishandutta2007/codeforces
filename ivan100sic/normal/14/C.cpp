#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;

	bool operator< (const pt& o) const {
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}

	bool operator== (const pt& o) const {
		return x == o.x && y == o.y;
	}

	pt operator- (const pt& o) const {
		return {x - o.x, y - o.y};
	}
};

pt a[4], b[4];

void no() {
	cout << "NO\n";
	exit(0);
}

bool orto(pt a, pt b) {
	return a.x*b.x + a.y*b.y == 0;
}

int c[4][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<4; i++)
		cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;

	set<pt> s;

	for (int i=0; i<4; i++) {
		s.insert(a[i]);
		s.insert(b[i]);
	}

	if (s.size() != 4)
		no();

	for (int i=0; i<4; i++)
		if (a[i] == b[i])
			no();

	for (int i=0; i<4; i++)
		if (a[i].x != b[i].x && a[i].y != b[i].y)
			no();

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (a[i] == b[j])
				c[i][j]++;
			if (b[i] == a[j])
				c[i][j]++;
			if (a[i] == a[j])
				c[i][j]++;
			if (b[i] == b[j])
				c[i][j]++;
		}
	}

	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (i != j && c[i][j] > 1)
				no();

	// otkrij da li je graf dobar (svi stepeni treba da budu 2)
	for (int i=0; i<4; i++) {
		int deg = 0;
		for (int j=0; j<4; j++) {
			if (i != j)
				deg += c[i][j];
		}
		if (deg != 2)
			no();
	}

	int x = 0;
	int p = -1, q = -1;
	for (int j=1; j<4; j++)
		if (c[0][j]) {
			if (p == -1)
				p = j;
			else
				q = j;
		}

	int y = p ^ q ^ x;

	cerr << "redosled duzi " << x << ' ' << p << ' ' << y << ' ' << q << '\n';
	int tacke[6] = {x, p, y, q, x, p};

	for (int i=0; i<4; i++) {
		int p = tacke[i];
		int q = tacke[i+1];

		// b[p] == a[q]
		if (b[p] == a[q]) {
			// nista
		} else if (a[p] == a[q]) {
			swap(a[p], b[p]);
		} else if (b[p] == b[q]) {
			swap(a[q], b[q]);
		} else {
			swap(a[p], b[p]);
			swap(a[q], b[q]);
		}
	}

	for (int i=1; i<=4; i++) {
		int j = tacke[i-1];
		int k = tacke[i];
		int l = tacke[i+1];
		if (!orto(a[k] - a[j], a[k] - a[l]))
			no();
	}

	cout << "YES\n";
	return 0;
}