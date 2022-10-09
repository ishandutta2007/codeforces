#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x, b = 1;
	cin >> x;
	for (int n=1;; n++) {
		if (x <= b+n-1) {
			cout << x-b+1 << '\n';
			return 0;
		} else {
			b += n;
		}
	}
}