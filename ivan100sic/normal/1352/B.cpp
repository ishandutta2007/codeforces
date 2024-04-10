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
		int n, k;
		cin >> n >> k;
		// neparni?
		if (n >= k && n % 2 == k % 2) {
			cout << "YES\n";
			for (int i=0; i<k-1; i++)
				cout << "1 ";
			cout << n-k+1 << '\n';
		} else if (n >= 2*k && n % 2 == 0) {
			cout << "YES\n";
			for (int i=0; i<k-1; i++)
				cout << "2 ";
			cout << n-2*k+2 << '\n';
		} else {
			cout << "NO\n";
		}
	}
}