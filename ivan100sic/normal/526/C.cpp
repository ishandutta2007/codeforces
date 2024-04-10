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

	ll a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	// max b*x+c*y s.t. d*x+e*y <= a, x >= 0, y >= 0
	ll sol = 0;

	for (ll x=0; x<=100000; x++)
		if (d*x <= a)
			sol = max(sol, b*x + c*((a-d*x) / e));

	swap(b, c);
	swap(d, e);

	for (ll x=0; x<=100000; x++)
		if (d*x <= a)
			sol = max(sol, b*x + c*((a-d*x) / e));

	cout << sol << '\n';
}