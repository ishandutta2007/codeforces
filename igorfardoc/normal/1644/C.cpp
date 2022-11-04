#include<bits/stdc++.h>
#define inf 1000000000000000000ll
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
		int n, x;
		cin >> n >> x;
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vl ans(n + 1, 0);
		for(int len = 1; len <= n; len++) {
			ll mx = -inf;
			ll now = 0;
			for(int i = 0; i < len; i++) {
				now += a[i];
			}
			for(int l = 0; l < n - len + 1; l++) {
				mx = max(mx, now);
				if(l == n - len) break;
				now -= a[l];
				now += a[l + len];
			}
			for(int i = 0; i <= n; i++) {
				int canadd = min(i, len);
				ans[i] = max(ans[i], mx + (ll)canadd * x);
			}
		}
		for(const auto& el : ans) {
			cout << el << ' ';
		}
		cout << '\n';
	}
}