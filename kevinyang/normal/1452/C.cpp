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
		int ans = 0;
		if(true){
			int cnt1 = 0;
			for(int i = 0; i<s.length(); i++){
				if(s[i]=='['){
					cnt1++;
				}
				if(s[i]==']'&&cnt1>0){
					ans++;
					cnt1--;
				}
			}
		}
		if(true){
			int cnt1 = 0;
			for(int i = 0; i<s.length(); i++){
				if(s[i]=='('){
					cnt1++;
				}
				if(s[i]==')'&&cnt1>0){
					ans++;
					cnt1--;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}