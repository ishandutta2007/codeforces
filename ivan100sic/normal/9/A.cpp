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

	int a, b;
	cin >> a >> b;
	int p = (7-max(a, b)), q = 6;
	int g = gcd(p, q);
	p /= g;
	q /= g;
	cout << p << '/' << q << '\n';	
}