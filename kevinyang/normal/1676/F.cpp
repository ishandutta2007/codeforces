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
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		set<int>s;
		map<int,int>hm;
		for(int i = 0; i<n; i++){
			s.insert(arr[i]);
			hm[arr[i]]++;
		}
		int mx = 0;
		pair<int,int>ans = {0,0};
		vector<int>vals;
		vals.push_back(-1);
		for(int nxt: s){
			vals.push_back(nxt);
		}
		int prev = -1;
		for(int i = 1; i<vals.size(); i++){
			if(vals[i]!=vals[i-1]+1){
				prev = -1;
			}
			if(hm[vals[i]]>=k){
				if(prev==-1)prev = vals[i];
				if(mx<vals[i]-prev+1){
					mx = vals[i]-prev+1;
					ans = {prev,vals[i]};
				}
			}
			else{
				prev = -1;
			}
		}
		if(mx==0){
			cout << "-1\n";
		}
		else{
			cout << ans.first << " " << ans.second << "\n";
		}
	}
	return 0;
}