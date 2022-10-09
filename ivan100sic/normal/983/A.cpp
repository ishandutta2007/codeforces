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

	int n;
	cin >> n;
	while (n--) {
		ll p, q, b;
		cin >> p >> q >> b;
		ll g = gcd(p, q);
		p /= g;
		q /= g;

		while (1) {
			ll t = gcd(q, b);
			if (t == 1)
				break;
			while (q % t == 0)
				q /= t;
		}

		if (q != 1)
			cout << "Infinite\n";
		else
			cout << "Finite\n";
	}
	

}