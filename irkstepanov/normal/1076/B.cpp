#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;

	ll p = n;
	for (ll d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			p = d;
			break;
		}
	}

	if (n == p) {
		cout << "1\n";
		return 0;
	}

	if (p == 2) {
		cout << n / p << "\n";
		return 0;
	}

	ll ans = 1;
	n -= p;
	p = 2;
	ans += n / p;
	cout << ans << "\n";

}