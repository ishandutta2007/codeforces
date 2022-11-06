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
		string s,t;
		cin >> s >> t;
		int ans = 0;
		for(int i = 0; i<n; i++){
			if(t[i]=='1'){
				if(i>0&&s[i-1]=='1'){
					s[i-1] = '0';
					ans++;
				}
				else if(s[i]=='0'){
					ans++;
				}
				else if(i<n-1&&s[i+1]=='1'){
					s[i+1] = '0';
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}