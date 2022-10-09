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

	ll l, r;
	cin >> l >> r;
	for (ll a=l; a<r; a++) {
		for (ll b=a+1; b<r; b++) {
			for (ll c=b+1; c<=r; c++) {
				if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) > 1) {
					cout << a << ' ' << b << ' ' << c << '\n';
					return 0;
				}
			}
		}
	}
	cout << "-1\n";
	return 0;
}