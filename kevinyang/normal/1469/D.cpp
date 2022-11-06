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
		int cur = n;
		vector<pair<int,int>>ans;
		while(cur>2){
			int val = ceil(sqrt(cur));
			int val2 = ceil(1.0*cur/val);
			for(int i = val+1; i<cur; i++){
				ans.push_back({i,n});

			}
			if(val==val2){
				ans.push_back({n,val});
				ans.push_back({val,n});
			}
			else{
				ans.push_back({n,val2});
				ans.push_back({val,n});
			}
			//cerr << val << " " << cur << "\n";
			cur = val;
		}
		cout << ans.size() << "\n";
		for(pair<int,int>p:ans){
			cout << p.first << " " << p.second << "\n";
		}
	}
	return 0;
}