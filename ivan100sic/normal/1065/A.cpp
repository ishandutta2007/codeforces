#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a, b, s, c, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> s >> a >> b >> c;

		ll x = s / (a*c);

		cout << b*x + s/c << '\n';
	}
}