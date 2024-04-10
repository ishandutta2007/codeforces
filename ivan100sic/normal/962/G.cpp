#include <bits/stdc++.h>

#define x1 asfpasokf
#define y1 ifjsiojofsj

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x1, y1, x2, y2, m;
int n;
int x[22222], y[22222];
int w[111111];

const int ULAZNA = 0;
const int IZLAZNA = 1;

bool unutra(int x, int y) {
	return x1 < x && x < x2 && y1 < y && y < y2;
}

bool unutraa(int x, int y) {
	return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

struct tacka {
	int tip, x, y, z;

	tacka(int tip, int x, int y) : tip(tip), x(x), y(y) {
		if (y == y2) {
			z = x - x1;
		} else if (x == x2) {
			z = (x2 - x1) + (y2 - y);
		} else if (y == y1) {
			z = (x2 - x1) + (y2 - y1) + (x2 - x);
		} else {
			z = (x2 - x1) + (y2 - y1) + (x2 - x1) + (y - y1);
		}
		z = m - z - 1;
	}
};

vector<tacka> pt;

int u[111111], v[111111];
bool vis[111111];

bool jbg() {
	int c = 0;
	for (int i=0; i<n; i++) {
		if (x[i] != x[i+1]) {
			int z = x[i] < x[i+1] ? 1 : -1;
			if (y[i] > y1)
				c += z;
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> x1 >> y1 >> x2 >> y2;
	swap(y1, y2);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
	}
	m = 2*(x2+y2-x1-y1);

	x[n] = x[0];
	y[n] = y[0];

	for (int i=0; i<n; i++) {
		if (unutra(x[i], y[i]) && !unutra(x[i+1], y[i+1])) {
			if (x[i] == x[i+1]) {
				int xx = x[i];
				int a = y[i];
				int b = y[i+1];
				int yy;
				if (a < b) {
					yy = y2;
				} else {
					yy = y1;
				}
				pt.push_back(tacka(IZLAZNA, xx, yy));
			} else {
				int yy = y[i];
				int a = x[i];
				int b = x[i+1];
				int xx;
				if (a < b) {
					xx = x2;
				} else {
					xx = x1;
				}
				pt.push_back(tacka(IZLAZNA, xx, yy));
			}
		} else if (!unutra(x[i], y[i]) && unutra(x[i+1], y[i+1])) {
			if (x[i] == x[i+1]) {
				int xx = x[i];
				int a = y[i];
				int b = y[i+1];
				int yy;
				if (a < b) {
					yy = y1;
				} else {
					yy = y2;
				}
				pt.push_back(tacka(ULAZNA, xx, yy));
			} else {
				int yy = y[i];
				int a = x[i];
				int b = x[i+1];
				int xx;
				if (a < b) {
					xx = x1;
				} else {
					xx = x2;
				}
				pt.push_back(tacka(ULAZNA, xx, yy));
			}
		} else if (!unutra(x[i], y[i]) && !unutra(x[i+1], y[i+1])) {
			// mozda smo prosli?
			if (x[i] == x[i+1] && x1 < x[i] && x[i] < x2) {
				int a = y[i];
				int b = y[i+1];
				if (a < b) {
					if (a <= y1 && y2 <= b) {
						pt.push_back(tacka(ULAZNA, x[i], y1));
						pt.push_back(tacka(IZLAZNA, x[i], y2));
					}
				} else {
					if (b <= y1 && y2 <= a) {
						pt.push_back(tacka(ULAZNA, x[i], y2));
						pt.push_back(tacka(IZLAZNA, x[i], y1));
					}
				}
			}

			if (y[i] == y[i+1] && y1 < y[i] && y[i] < y2) {
				int a = x[i];
				int b = x[i+1];
				if (a < b) {
					if (a <= x1 && x2 <= b) {
						pt.push_back(tacka(ULAZNA, x1, y[i]));
						pt.push_back(tacka(IZLAZNA, x2, y[i]));
					}
				} else {
					if (b <= x1 && x2 <= a) {
						pt.push_back(tacka(ULAZNA, x2, y[i]));
						pt.push_back(tacka(IZLAZNA, x1, y[i]));
					}
				}
			}
		}
	}

	if (pt.size() == 0) {
		if (unutraa(x[0], y[0]))
			cout << 1;
		else if (jbg())
			cout << 1;
		else
			cout << 0;
		return 0;
	}

	if (pt[0].tip == IZLAZNA) {
		rotate(pt.begin(), pt.begin() + 1, pt.end());
	}

	for (int i=0; i<(int)pt.size(); i+=2) {
		int z1 = pt[i].z;
		int z2 = pt[i+1].z;
		int j = (i+2) / 2;

		w[z1] = -j;
		w[z2] = j;

		u[j] = z1;
		v[j] = z2;
	}

	int sol = 0;

	for (int i=0; i<m; i++) {
		int x = i;
		if (!vis[x] && w[x] > 0) {
			sol++;
			while (1) {
				if (vis[x])
					break;
				vis[x] = 1;
				if (w[x] == 0)
					x = (x+1) % m;
				else if (w[x] < 0)
					x = u[-w[x]] ^ v[-w[x]] ^ x;
				else
					x = (x+1) % m;
			}
		}
	}

	cout << sol << '\n';

}