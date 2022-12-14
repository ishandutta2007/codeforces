#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> lrm(n);
		vector<pair<int, int>> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i].first >> a[i].second; --a[i].first, --a[i].second;
			lrm[a[i].first].push_back(a[i].second);
		}
		for(int i = 0; i < n; ++i){
			sort(lrm[i].begin(), lrm[i].end());
		}
		for(int i = 0; i < n; ++i){
			int p = lower_bound(lrm[a[i].first].begin(), lrm[a[i].first].end(), a[i].second) - lrm[a[i].first].begin();
			int l = a[i].first - 1;
			if(p - 1 >= 0) l = lrm[a[i].first][p - 1];
			cout << a[i].first + 1 << ' ' << a[i].second + 1 << ' ' << l + 2 << '\n';
		}
	}
	return 0;
}