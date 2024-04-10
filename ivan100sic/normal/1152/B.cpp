#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// 100111
// xor sa 5
// 101000
// dodaj 1
// 101001
// 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x, z = 0;
	cin >> x;

	basic_string<int> sol;
	if (x % 2 == 0) {
		while (x != (x & -x)) {
			int y = x & -x;
			sol += round(log2(ld(y)));
			x ^= y-1;
			x++;
			z += 2;
		}

		{
			int y = x & -x;
			sol += round(log2(ld(y)));
			x ^= y-1;
			z += 1;
		}
	} else {
		while (x > 1) {
			int y = 1 << (32 - __builtin_clz(x));
			sol += round(log2(ld(y)));
			x ^= y-1;
			x++;
			cerr << "x: " << x << '\n';
			z += 2;
		}
	}

	cout << z << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}