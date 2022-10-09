#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

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

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int g = 0;
	for (int i=0; i<n; i++)
		g = gcd(g, a[i]);

	for (int i=0; i<n; i++) {
		int x = a[i] / g;
		while (x % 2 == 0) 
			x /= 2;
		while (x % 3 == 0)
			x /= 3;
		if (x > 1)
			return cout << "No\n", 0;
	}
	cout << "Yes\n";
}