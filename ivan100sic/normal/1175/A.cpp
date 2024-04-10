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
		ll n, k;
		cin >> n >> k;
		ll z = 0;
		while (n > 0) {
			if (n % k) {
				z += n % k;
				n -= n % k;
			} else {
				n /= k;
				z++;
			}
		}
		cout << z << '\n';
	}
}