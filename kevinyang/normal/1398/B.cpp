#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<int>pos;
		int cur = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='1')cur++;
			else{
				pos.push_back(cur); cur = 0;
			}
		}
		pos.push_back(cur);
		sort(pos.begin(),pos.end());
		int ans = 0;
		for(int i = pos.size()-1; i>=0; i-=2){
			ans+=pos[i];
		}
		cout << ans << "\n";
	}
	return 0;
}