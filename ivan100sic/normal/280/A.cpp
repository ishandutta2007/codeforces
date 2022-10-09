#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld kv(ld x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cout.precision(20);
	cout << fixed;

	ld w, h, a;
	cin >> w >> h >> a;
	if (h > w)
		swap(h, w);
	
	a = min(a, 180 - a);

	if (a == 0) {
		cout << w*h << '\n';
		return 0;
	}

	a /= 57.2957795130823208767;

	if (atan(h/w) > a/2) {
		// plitko
		ld s1 = (h - w*sin(a)/(1 + cos(a)))
			/ (1 - kv(sin(a)) / (cos(a) + 1) + cos(a));

		ld s2 = (w - sin(a) * s1) / (1 + cos(a));

		cout << w*h - (kv(s1) + kv(s2)) * sin(a) * cos(a) << '\n';
	} else {
		cout << h*h / sin(a) << '\n';
	}
}