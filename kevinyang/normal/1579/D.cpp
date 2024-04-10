#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>freq(200005);
bool comp(int a, int b){
	return freq[a]<freq[b];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		vector<int>vals;
		vals.push_back(0);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			freq[i] = arr[i];
			for(int j = 0; j<freq[i]; j++){
				vals.push_back(i);
			}
		}
		sort(vals.begin(),vals.end(),comp);
		vector<pair<int,int>>ans;
		for(int i = 1; i<=((int)vals.size()-1)/2; i++){
			if(vals[i]!=vals[i+(int)vals.size()/2]){
				ans.push_back({vals[i],vals[i+(int)vals.size()/2]});
			}
		}
		cout << ans.size() << "\n";
		for(pair<int,int>nxt: ans){
			cout << nxt.first << " " << nxt.second << "\n";
		}
		for(int nxt: vals){
			freq[nxt] = 0;
		}
	}
	return 0;
}