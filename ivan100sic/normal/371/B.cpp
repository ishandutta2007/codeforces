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

int z;

void radi(int& x, int y) {
	while (x % y == 0) {
		x /= y;
		z++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	a /= g;
	b /= g;

	// napravi da budu 1
	radi(a, 2);
	radi(a, 3);
	radi(a, 5);
	radi(b, 2);
	radi(b, 3);
	radi(b, 5);

	if (a == 1 && b == 1)
		cout << z;
	else
		cout << -1;

}