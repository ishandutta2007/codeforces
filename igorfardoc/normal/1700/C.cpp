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
		ll ans = 0;
		ll now = 0;
		for(int i = 1; i < n; i++) {
			a[i] -= now;
			ll mn = min(a[i], a[i - 1]);
			ll mx = max(a[i], a[i - 1]);
			ans += mx - mn;
			now += a[i] - mn;
			a[i] = mn;
		}
		ans += abs(a[n - 1]);
		cout << ans << '\n';
	}
}