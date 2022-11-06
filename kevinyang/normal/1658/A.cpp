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
		int ans = 0;
		int prev = -3;
		for(int i = 0; i<n; i++){
			if(s[i]=='0'){
				ans+=max(0LL,3-(i-prev));
				prev = i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}