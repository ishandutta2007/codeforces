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
		int n, k;
		cin >> n >> k;
		vi a(n);
		int ans = 100000;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int up = 0; up <= 3000; up++) {
			int mx = 0;
			int mn = 3000;
			for(int i = 0; i < n; i++) {
				int here = 0;
				if(a[i] / k >= up) {
					here = a[i] / k;
				} else {
					if(a[i] / up != 0 && a[i] / (a[i] / up) <= up) {
						here = a[i] / (a[i] / up);
					} else {
						here = a[i] / ((a[i] - 1) / up + 1);
					}
				}
				mx = max(mx, here);
				mn = min(mn, here);
			}
			ans = min(ans, mx - mn);
		}
		cout << ans << '\n';

	}
}