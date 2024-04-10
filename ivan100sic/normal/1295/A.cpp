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
		if (n % 2 == 0) {
			cout << string(n/2, '1') << '\n';
		} else {
			cout << 7 << string(n/2-1, '1') << '\n';
		}
	}
}