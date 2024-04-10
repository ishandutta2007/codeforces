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
		int a, b;
		cin >> a >> b;
		if (2*a <= b) {
			cout << a << ' ' << 2*a << '\n';
		} else {
			cout << "-1 -1\n";
		}
	}
}