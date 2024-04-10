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
		vvi dp1(n, vi(n));
		for(int i = 0; i < n; i++) {
			dp1[i][0] = 0;
			for(int j = 1; j <= i; j++) {
				dp1[i][j] = (dp1[i][j - 1] + (a[j - 1] < a[i]));
			}
		}
		vvi dp2(n, vi(n));
		for(int i = 0; i < n; i++) {
			dp2[i][n - 1] = 0;
			for(int j = n - 2; j >= i; j--) {
				dp2[i][j] = (dp2[i][j + 1] + (a[j + 1] < a[i]));
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				ans += (ll)dp1[j][i] * dp2[i][j];
			}
		}
		cout << ans << '\n';
	}
}