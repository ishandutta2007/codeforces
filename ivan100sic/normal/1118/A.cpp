#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		ll n, a, b, z = 0;
		cin >> n >> a >> b;
		if (n % 2)
			z += a;
		z += n/2 * min(2*a, b);
		cout << z << '\n';
	}
}