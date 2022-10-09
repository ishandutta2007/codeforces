#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, g;

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

	cin >> n >> k;
	g = k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		g = gcd(g, x);
	}
	cout << k/g << '\n';
	for (int i=0; i<k; i+=g)
		cout << i << ' ';
	cout << '\n';
}