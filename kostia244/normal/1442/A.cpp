#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
using ll = long long;
const int maxn = 101;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		ll dec = 0;
		for(int i = 0; i < n; i++) {
			a[i] -= dec;
			if(i+1 < n && (a[i+1]-dec) > a[i]) dec += (a[i+1]-dec)-a[i];
		}
		cout << (*min_element(all(a)) < 0 ? "NO" : "YES") << '\n';
	}
}