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

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll z = 0;
		for (ll i=1; i<=n; i<<=1)
			z += i;
		cout << n*(n+1) / 2 - z - z << '\n';
	}
}