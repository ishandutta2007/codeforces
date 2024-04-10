// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll m, d, w;
		cin >> m >> d >> w;

		ll a = min(m, d);
		// razlika x-y mora da bude dopuna za d-1 do 0
		ll r = w / gcd(w, d-1);
		ll kol = (a-1) / r;
		ll c = a*kol - kol*(1+kol)*r / 2;
		cout << c << '\n';
	}
}