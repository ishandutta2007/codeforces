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

	ll a, b, c;
	cin >> a >> b >> c;

	ll sol = 0;
	for (int i=0; i<3 && i<=min({a, b, c}); i++) {
		sol = max(sol, (a-i)/3 + (b-i)/3 + (c-i)/3 + i);
	}

	cout << sol << "\n";
}