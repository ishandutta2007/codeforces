#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, xc, yc;
	cin >> n >> xc >> yc;
	set<pair<int, int>> s;
	while (n--) {
		int x, y;
		cin >> x >> y;
		x -= xc;
		y -= yc;
		int g = gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		if (x < 0) {
			x *= -1;
			y *= -1;
		} else if (x == 0 && y < 0) {
			y *= -1;
		}
		s.insert({x, y});
	}
	cout << size(s) << '\n';
}