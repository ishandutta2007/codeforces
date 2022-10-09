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
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			x = abs(x) * (i % 2 ? -1 : 1);
			cout << x << ' ';
		}
		cout << '\n';
	}
}