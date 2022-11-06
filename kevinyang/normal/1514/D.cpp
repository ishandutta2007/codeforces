#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	vector<vector<int>>ind(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		ind[arr[i]].push_back(i);
	}
	for(int i = 1; i<=n; i++){
		ind[i].push_back(n+1);
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		int mxcnt = 0;
		for(int t = 0; t<50; t++){
			int idx = rng()%(r-l+1)+l;
			int val = arr[idx];
			int idx1 = lower_bound(ind[val].begin(),ind[val].end(),l)-ind[val].begin();
			int idx2 = upper_bound(ind[val].begin(),ind[val].end(),r)-ind[val].begin();
			mxcnt = max(mxcnt,idx2-idx1);
		}
		if(mxcnt<=(r-l+1+1)/2)cout << "1\n";
		else{
			mxcnt-=(r-l+1)-mxcnt; mxcnt--;
			cout << mxcnt+1 << "\n";
		}
	}
	return 0;
}