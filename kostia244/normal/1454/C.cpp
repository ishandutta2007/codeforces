#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1<<20;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--) {
		int n;cin >> n;
		vector<int> a(n);
		map<int, int> cnt;
		for(auto &i : a) cin >> i, cnt[i]++;
		for(int i = 1; i < n; i++) if(a[i] == a[i-1]) cnt[a[i]]--;
		int ans = n+1;
		for(auto [x, y] : cnt) ans = min(ans, y + 1 - (a[0]==x) - (a.back()==x));
		cout << ans << '\n';
	}
}