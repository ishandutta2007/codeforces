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
		string s;
		cin >> s;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			if(s[i-1]=='L'){
				arr[i] = (int)-1e6;
			}
			if(s[i-1]=='R'){
				arr[i] = (int)1e6;
			}
			if(s[i-1]=='U'){
				arr[i] = 1;
			}
			if(s[i-1]=='D'){
				arr[i] = -1;
			}
		}
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		map<int,int>hm;
		hm[0] = 1;
		pair<int,int>p;
		int ans = 1e18;
		for(int i = 1; i<=n; i++){
			if(hm[psa[i]]){
				if(i+1-hm[psa[i]]<ans){
					p = {hm[psa[i]]-1,i};
				}
				ans = min(ans,i+1-hm[psa[i]]);
			}
			hm[psa[i]] = i+1;
		}
		if(ans==1e18){
			cout << "-1\n";
		}
		else{
			cout << p.first+1 << " " << p.second << "\n";
		}
	}
	return 0;
}