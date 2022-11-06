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
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vl dp1(n + 2), dp2(n + 2);
		for(int i = 1; i < n - 1; i+=2) {
			ll bef = 0;
			if(i != 1) bef = dp1[i - 2];
			dp1[i] = bef + max(0, max(a[i + 1], a[i - 1]) + 1 - a[i]);
		}
		for(int i = n - 2; i > 0; i-=2) {
			ll bef = 0;
			if(i != n - 2) bef = dp2[i + 2];
			dp2[i] = bef + max(0, max(a[i + 1], a[i - 1]) + 1 - a[i]);
		}
		if(n % 2 == 1) {
			cout << dp1[n - 2] << '\n';
		} else {
			ll ans = dp2[2];
			for(int i = 1; i < n - 1; i+=2) {
				ans = min(ans, dp1[i] + dp2[i + 3]);
			}
			cout << ans << '\n';
		}
	}
}