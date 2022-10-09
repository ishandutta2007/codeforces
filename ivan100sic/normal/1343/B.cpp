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
		int n;
		cin >> n;
		if (n % 4 == 2) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		ll z = 0;
		for (int i=2; i<=n; i+=2)
			z += i, cout << i << ' ';
		for (int i=1; i<n-2; i+=2)
			z -= i, cout << i << ' ';
		cout << z << '\n';
	}
}