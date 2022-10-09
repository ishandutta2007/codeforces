#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
	bool operator== (const pt& o) const {
		return x == o.x && y == o.y;
	}

	pt operator- (const pt& o) const {
		return {x-o.x, y-o.y};
	}
};

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

bool right(pt a, pt b, pt c) {
	if (a == b || b == c || c == a) return false;
	if (sp(b-a, b-c) == 0) return true;
	if (sp(a-b, a-c) == 0) return true;
	if (sp(c-a, c-b) == 0) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pt a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	if (right(a, b, c))
		return cout << "RIGHT\n", 0;

	for (int i=0; i<3; i++) {
		pt t = a;
		a = b;
		b = c;
		c = t;
		pt d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
		for (pt e : d) {
			if (right(a-e, b, c))
				return cout << "ALMOST\n", 0;
		}
	}

	cout << "NEITHER\n";
}