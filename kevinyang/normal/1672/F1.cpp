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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<vector<int>>idx(n+1);
		set<int>s;
		for(int i = 1; i<=n; i++){
			s.insert(arr[i]);
			idx[arr[i]].push_back(i);
		}
		vector<int>ans(n+1);
		while(s.size()){
			vector<int>ind;
			vector<int>val;
			vector<int>rem;
			for(int nxt: s){
				ind.push_back(idx[nxt].back());
				idx[nxt].pop_back();
				if(idx[nxt].size()==0){
					rem.push_back(nxt);
				}
				val.push_back(nxt);
			}
			for(int nxt: rem){
				s.erase(nxt);
			}
			vector<int>id;
			for(int i = 1; i<ind.size(); i++){
				id.push_back(ind[i]);
			}
			id.push_back(ind[0]);
			for(int i = 0; i<ind.size(); i++){
				ans[id[i]] = val[i];
			}
		}
		for(int i = 1; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}