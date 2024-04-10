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
		ll n;
		cin >> n;
		for (ll k=3; k<=n; k=2*k+1) {
			if (n % k == 0) {
				cout << n / k << '\n';
				break;
			}
		}
	}
}

// THE VERDICT WAS DENIAL OF JUDGEMENT ASSHOLES