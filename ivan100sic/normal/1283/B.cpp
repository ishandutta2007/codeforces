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

	int t;
	cin >> t;
	while (t--) {
		ll n, k, x;
		cin >> n >> k;

		if (n % k <= k/2)
			x = n;
		else
			x = n - (n % k) + k/2;
		cout << x<< '\n';
	}
}