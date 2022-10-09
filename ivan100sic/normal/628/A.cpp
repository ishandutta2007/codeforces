// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, b, p, a = 0;
	cin >> n >> b >> p;
	int c = n*p;

	while (n > 1) {
		int k = 1;
		while (k*2 <= n) k *= 2;
		n -= k / 2;
		a += (2*b + 1) * (k / 2);
	}

	cout << a << ' ' << c << '\n';
}