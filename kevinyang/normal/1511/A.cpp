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
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			if(x%2==1)ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}