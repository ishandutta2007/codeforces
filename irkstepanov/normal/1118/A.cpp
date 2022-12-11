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

	int tt;
	cin >> tt;

	while (tt--) {
		ll n, a, b;
		cin >> n >> a >> b;
		ll ans = a * n;
		ans = min(ans, (n / 2) * b + a * (n % 2));
		cout << ans << "\n";
	}
	
}