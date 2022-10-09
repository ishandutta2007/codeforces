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
		ll n, x;
		cin >> n >> x;
		if (n <= 2) {
			cout << "1\n";
		} else {
			cout << (n-3)/x + 2 << '\n';
		}
	}
}