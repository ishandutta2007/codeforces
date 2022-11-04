#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vl a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll sum = 0;
		for(int i = 0; i < n; i++) sum += a[i];
		if(sum + (ll)a[0] * (n - 2) > 0 || sum + (ll)a[n - 1] * (n - 2) < 0) {
			cout << "INF\n";
			continue;
		}
		ll ans = -2e18;
		ll l = 0;
		ll r = sum;
		for(int i = 0; i < n - 1; i++) {
			l += a[i];
			r -= a[i];
			ll t = -a[i];
			ll here = (a[n - 1] + t) * (l + (i + 1) * t) + (a[0] + t) * (r + (n - i - 1) * t) - (a[0] + t) * (a[n - 1] + t) - (ll)t * t * (n - 1);
			ans = max(ans, here);
		}
		cout << ans << '\n';
	}
}