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
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;

		ll sol = 4e18;
		ll aa = max(a-n, x);
		ll bb = max(b-(n-(a-aa)), y);

		sol = min(sol, aa*bb);

		swap(a, b);
		swap(x, y);

		aa = max(a-n, x);
		bb = max(b-(n-(a-aa)), y);

		sol = min(sol, aa*bb);

		cout << sol << '\n';
	}
}