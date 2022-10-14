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
		int res = -2;
		for(int i = 0; i < n; i++) if(cnt[a[i]] == 1) {
			if(res == -2 || a[res] > a[i]) res = i;
		}
		cout << ++res << '\n';
	}
}