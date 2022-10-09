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
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int g = 0;
		for (int i=0; i<n; i++) {
			auto it = max_element(begin(a), end(a), [g](int x, int y) { return gcd(x, g) < gcd(y, g); });
			cout << *it << ' ';
			g = gcd(g, *it);
			a.erase(it);
		}
		cout << '\n';
	}
}