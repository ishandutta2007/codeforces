#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	ll a, b;
	cin >> a >> b;

	ll n = min(a, b);
	ll ans = 1;
	for (ll i = 1; i <= n; ++i) {
		ans *= i;
	}
	cout << ans << "\n";

}