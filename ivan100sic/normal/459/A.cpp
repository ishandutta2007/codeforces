#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d;
	if (a == c) {
		e = g = a + abs(b-d);
		f = b;
		h = d;
	} else if (b == d) {
		f = h = b + abs(a-c);
		e = a;
		g = c;
	} else if (abs(a-c) == abs(b-d)) {
		e = a;
		f = d;
		g = c;
		h = b;
	} else {
		cout << "-1\n";
		return 0;
	}

	cout << e << ' ' << f << ' ' << g << ' ' << h << '\n';
}