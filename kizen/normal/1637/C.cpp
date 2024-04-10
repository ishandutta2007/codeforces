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
		vector<int> a(n);
		int df1 = 0;
		for(auto&i:a){
			cin >> i;
		}
		for(int i = 1; i < n - 1; ++i){
			if(a[i] != 1) df1 = 1;
		}
		if(!df1 || (n == 3 && a[1] % 2)){
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		for(int i = 1; i < n - 1; ++i){
			ans += a[i] / 2 + a[i] % 2;
		}
		cout << ans << '\n';
	}
	return 0;
}