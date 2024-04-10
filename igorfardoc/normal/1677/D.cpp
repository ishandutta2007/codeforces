#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;


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
		int n, k;
		cin >> n >> k;
		vi a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		int ans = 1;
		for(int i = 0; i < k; i++) {
			if(a[n - 1 - i] > 0) ans = 0;
		}
		for(int i = 1; i <= k; i++) {
			ans = (ll)ans * i % mod;
		}
		for(int i = k; i < n; i++) {
			if(a[i - k] == -1) {
				ans = (ll)ans * (i + 1) % mod;
			} else if (a[i - k] == 0) {
				ans = (ll)ans * (k + 1) % mod;
			}
		}
		cout << ans << '\n';
	}
}