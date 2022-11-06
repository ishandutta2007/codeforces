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
		int n = s.length();
		int ans = 0;
		for(int i = 1; i<n; i++){
			if(i>0){
				if(s[i]==s[i-1]){
					s[i] = '.'; ans++;
					continue;
				}
			}
			if(i>1){
				if(s[i]==s[i-2]){
					s[i] = '.'; ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}