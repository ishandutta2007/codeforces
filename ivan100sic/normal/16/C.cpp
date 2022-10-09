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

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int g = gcd(x, y);

	x /= g;
	y /= g;

	int k = min(a/x, b/y);
	cout << x*k << ' ' << y*k << '\n';
}