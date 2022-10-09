#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ld x, y;
	bool na_pravoj;
};

basic_string<pt> e;
ld f[55][55];

ld L1(pt a, pt b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

ld kv(ld x) {
	return x*x;
}

ld L2(pt a, pt b) {
	return sqrt(kv(a.x - b.x) + kv(a.y - b.y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cout.precision(20);
	cout << fixed;

	ld a, b, c;
	cin >> a >> b >> c;

	ld x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	// ax + by + c = 0
	if (a == 0 || b == 0) {
		cout << abs(x1-x2) + abs(y1-y2) << '\n';
		return 0;
	}

	e += {x1, y1, false};
	e += {x2, y2, false};
	e += {x1, (-c-a*x1) / b, true};
	e += {x2, (-c-a*x2) / b, true};
	e += {(-c-b*y1) / a, y1, true};
	e += {(-c-b*y2) / a, y2, true};

	for (int i=0; i<6; i++)
		for (int j=0; j<6; j++) {
			if (i == j)
				f[i][j] = 0;
			else {
				if (e[i].na_pravoj && e[j].na_pravoj)
					f[i][j] = L2(e[i], e[j]);
				else
					f[i][j] = L1(e[i], e[j]);
			}
		}

	for (int k=0; k<6; k++)
		for (int i=0; i<6; i++)
			for (int j=0; j<6; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

	cout << f[0][1] << '\n';
}