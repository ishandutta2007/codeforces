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
		map<int, int> b, c;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			b[x]++;
		}
		for (auto [k, v] : b) {
			c[v]++;
		}
		auto [u, v] = *c.rbegin();
		cout << (n-v)/(u-1)-1 << '\n';
	}
}