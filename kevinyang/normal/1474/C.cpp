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
		n*=2;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		for(int i = 0; i<n-1; i++){
			multiset<int>s;
			for(int nxt: arr)s.insert(nxt);
			vector<pair<int,int>>ans;
			bool f = true;
			int prev = arr[i]+arr[n-1];
			for(int j = 0; j<n/2; j++){
				int v1 = *(--s.end());
				s.erase(s.lower_bound(v1));
				int v2 = prev-v1;
				if(s.lower_bound(v2)==s.end()||*s.lower_bound(v2)!=v2){
					f = false;
					break;
				}
				s.erase(s.lower_bound(v2));
				ans.push_back({v1,v2});
				prev = max(v1,v2);
			}
			if(f){
				cout << "YES\n";
				cout << ans[0].first+ ans[0].second << "\n";
				for(pair<int,int>nxt: ans){
					cout << nxt.first << " " << nxt.second << "\n";
				}
				break;
			}
			else{
				if(i==n-2){
					cout << "NO\n";
					break;
				}
			}
		}

	}
	return 0;
}