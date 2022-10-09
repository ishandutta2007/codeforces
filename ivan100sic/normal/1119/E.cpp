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

	int n;
	cin >> n;
	ll z = 0, p = 0;
	while (n--) {
		ll x;
		cin >> x;
		ll w = min(p, x/2);
		z += w;
		p -= w;
		x -= 2*w;
		z += x/3;
		x %= 3;
		p += x;
	}
	cout << z << '\n';
}