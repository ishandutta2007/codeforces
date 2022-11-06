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
		vector<int>a(11);
		for(int i = 0; i<n; i++){
			int x,y;
			cin >> x >> y;
			a[y] = max(a[y],x);
		}
		bool f = true;
		int ans = 0;
		for(int i = 1; i<=10; i++){
			if(a[i]==0)f = false;
			ans+=a[i];
		}
		if(f)cout << ans << "\n";
		else cout << "MOREPROBLEMS\n";
	}
	return 0;
}