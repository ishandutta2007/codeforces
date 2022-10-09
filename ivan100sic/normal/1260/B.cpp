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
		if ((a+b) % 3 == 0 && min(a, b) * 2 >= max(a, b)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}