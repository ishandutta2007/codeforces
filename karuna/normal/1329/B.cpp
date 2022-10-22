#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		ll d, m; cin >> d >> m;

		ll ans = 1, sum = 0;
		for (ll i=1; ; i<<=1) {
			if (sum + i >= d) break;
			ans = (ans * (i+1))%m;
			sum += i;
		}
		ans = (ans * (d-sum+1))%m;
		ans = (ans + m-1)%m;
		cout << ans << '\n';
	}
}