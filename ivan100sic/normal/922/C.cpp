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

	ll n, k;
	cin >> n >> k;
	for (ll i=1; i<=k; i++) {
		if (n % i != (i-1)) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}