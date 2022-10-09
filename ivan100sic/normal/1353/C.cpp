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
		ll n, z;
		cin >> n;

		if (n % 2 == 1)
		 	z = n*(n+1)*(n-1) / 3;
		else
			z = (n + 2*n*n*n) / 6;

		cout << z << '\n';
	}
}