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

ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int l, r, x, y, z = 0;
	cin >> l >> r >> x >> y;
	set<int> d;
	for (int i=1; i*i<=y; i++) {
		if (y % i == 0) {
			d.insert(i);
			d.insert(y / i);
		}
	}
	for (int a : d) {
		for (int b : d) {
			if (lcm(a, b) == y && gcd(a, b) == x
				&& l <= a && a <= r
				&& l <= b && b <= r)
				z++;
		}
	}
	
	cout << z << '\n';
}