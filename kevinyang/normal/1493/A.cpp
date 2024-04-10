#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>ans;
		for(int i = (k+1)/2; i<=n; i++){
			if(i!=k)
			ans.push_back(i);
		}
		cout << ans.size() << "\n";
		for(int nxt: ans)cout << nxt << " ";
		cout << "\n";
	}
	return 0;
}