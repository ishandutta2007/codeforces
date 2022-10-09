// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, a[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];

	if (n == 1) {
		cout << "1 1\n";
		cout << -a[0] << '\n';
		cout << "1 1\n0\n1 1\n0\n";
		return 0;
	}

	cout << "1 " << n << '\n';
	for (int i=0; i<n; i++) {
		ll r = (a[i] % (n - 1) + (n - 1)) % (n - 1);
		cout << -r*n << ' ';
		a[i] -= r*n;
	}
	cout << '\n';

	cout << "1 " << n-1 << '\n';
	for (int i=0; i<n-1; i++) {
		cout << -a[i] << ' ';
		a[i] = 0;
	}
	cout << '\n';

	cout << "2 " << n << '\n';
	for (int i=1; i<n; i++) {
		cout << -a[i] << ' ';
	}
	cout << '\n';

}