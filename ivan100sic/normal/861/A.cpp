#include <bits/stdc++.h>
using namespace std;

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long a, b, x;
	cin >> a >> b;
	long long t = 1;
	for (int i=1; i<=b; i++) {
		t *= 10;
	}
	auto g = eea(a, t, x, x);
	cout << a * t / g;
}