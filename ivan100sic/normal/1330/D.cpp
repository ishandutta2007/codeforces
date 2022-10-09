// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		ll d, m;
		cin >> d >> m;
		vector<ll> s(50), w(50);
		for (ll l=1; l<=44; l++) {
			s[l] = max(0ll, min((1ll << l) - 1, d) - (1ll << (l - 1)) + 1);
		}
		for (ll l=44; l>=0; l--) {
			w[l] = 1;
			for (int i=l+1; i<=44; i++)
				w[l] = (w[l] + w[i] * s[i]) % m;
		}
		cout << (w[0] + m - 1) % m << '\n';
	}
}

// I will still practice daily...