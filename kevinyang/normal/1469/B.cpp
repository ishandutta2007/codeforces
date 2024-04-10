#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		int cur = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			cur+=x;
			ans = max(ans,cur);
		}
		int m;
		cin >> m;
		int mx = 0;
		cur = 0;
		for(int i = 0; i<m; i++){
			int x;
			cin >> x;
			cur+=x;
			mx = max(mx,cur);
		}
		cout << ans+mx << "\n";
	}
	return 0;
}