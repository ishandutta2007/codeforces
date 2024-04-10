#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b;
	while (1) {
		if (a == 0 || b == 0)
			break;
		if (a >= 2*b) {
			a -= a/(2*b)*2*b;
		} else if (b >= 2*a) {
			b -= b/(2*a)*2*a;
		} else
			break;
	}
	cout << a << ' ' << b << '\n';
}