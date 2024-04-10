#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		double ans = 0;
		double cur = 1;
		vector<int>arr(n+1);
		int mx = 0;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = n; i>0; i--){
			if(arr[i]!=i){
				mx = i; break;
			}
		}
		if(mx==0){
			for(int i = 1; i<=m; i++){
				int r; double p;
				cin >> r >> p;
			}
			cout << "1\n";
			continue;
		}
		for(int i = 1; i<=m; i++){
			int r; double p;
			cin >> r >> p;
			if(r>=mx){
				ans+=cur*p;
				cur = cur*(1.0-p);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}