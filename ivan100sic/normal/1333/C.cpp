// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	map<ll, int> seen;
	int n;
	cin >> n;
	seen[0] = 0;
	ll z = 0, sol = 0;
	int r = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z += x;
		if (seen.count(z)) {
			r = max(r, seen[z] + 1);
		}
		seen[z] = i;
		sol += i-r;
	}
	cout << sol << '\n';
}