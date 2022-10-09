#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	cin >> n >> k;

	if (n*(n-1) / 2 < k) {
		cout << "Impossible\n";
		return 0;
	}

	ll f = 0;
	while (f * (f+1) / 2 <= k) {
		f++;
	}

	cerr << f << '\n';

	ll un = 0;
	ll br = 0;

	for (ll i=1; i<=f; i++) {
		cout << '(';
		br++;
		un++;
	}

	ll rest = f - (k - f * (f-1) / 2);
	cerr << rest << '\n';

	for (ll i=1; i <= rest; i++) {
		cout << ')';
		un--;
	}

	if (br < n) {
		cout << "()";
		br++;
	}

	while (un--) {
		cout << ")";
	}

	while (br < n) {
		cout << "()";
		br++;
	}

	

	


}