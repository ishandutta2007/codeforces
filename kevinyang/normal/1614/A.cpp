#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,l,r,k;
		cin >> n >> l >> r >> k;
		vector<int>arr;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			if(x>=l&&x<=r)arr.push_back(x);
		}
		sort(arr.begin(),arr.end());
		int cnt = 0;
		for(int nxt: arr){
			if(k>=nxt){
				k-=nxt;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}