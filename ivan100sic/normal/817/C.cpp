#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, s;

ll ds(ll z) {
	ll w = 0;
	while (z) {
		w += z % 10;
		z /= 10;
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	ll z = 0;
	for (ll b=s; b<=min(n, s+200); b++) {
		if (b - ds(b) >= s)
			z++;
	}
	z += n - min(n, s+200);
	cout << z << '\n';
}