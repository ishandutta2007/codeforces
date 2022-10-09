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
		int l, r;
		cin >> l >> r;
		if (l*2 >= r+1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}