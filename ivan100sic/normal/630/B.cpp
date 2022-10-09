// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ld n, t;
	cin >> n >> t;
	cout << setprecision(20) << fixed << n * exp(1.0999999939500000444e-8*t) << '\n';
}