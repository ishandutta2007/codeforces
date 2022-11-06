#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	int mxn = (int)1e7+5;
	vector<int>sum(mxn);
	for(int i = 1; i<=(int)1e7; i++){
		for(int j = i; j<mxn; j+=i){
			sum[j]+=i;
		}
	}
	vector<int>ans(mxn,(int)1e18);
	for(int i = 1; i<mxn; i++){
		if(sum[i]<mxn){
			ans[sum[i]] = min(ans[sum[i]],i);
		}
	}
	while(t--){
		int n;
		cin >> n;
		if(ans[n]==(int)1e18)cout << "-1\n";
		else cout << ans[n] << "\n";
	}
	return 0;
}