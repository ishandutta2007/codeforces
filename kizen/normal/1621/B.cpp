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
		vector<int> l = {(int)1e18, 0, -1};
		vector<int> r = {-(int)1e18, 0, -1};
		int al = (int)1e18;
		for(int i = 0; i < n; ++i){
			int x, y, z; cin >> x >> y >> z;
			if(x < l[0] || y > r[0]) al = (int)1e18;
			if(x <= l[0] && y >= r[0]){
				mi(al, z);
			}
			l = min(l, {x, z, i});
			r = max(r, {y, -z, i});
			int ans = min(al, l[1] - r[1]);
			cout << ans << '\n';
		}
	}
	return 0;
}