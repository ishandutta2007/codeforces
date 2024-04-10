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

	int n, a, b, g;
	set<int> d;
	cin >> a >> b;
	g = gcd(a, b);
	for (int i=1; i*i<=g; i++) {
		if (g % i == 0) {
			d.insert(i);
			d.insert(g / i);
		}
	}

	cin >> n;
	while (n--) {
		int l, r, z = -1;
		cin >> l >> r;
		for (int x : d) {
			if (l <= x && x <= r)
				z = x;
		}
		cout << z << '\n';
	}
}