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
		string s;
		cin >> s;
		int start = 0; int end = 0;
		for(int i = 0; i<n; i++){
			if(s[i]=='*'){
				start = i;
				break;
			}
		}
		for(int i = n-1; i>=0; i--){
			if(s[i]=='*'){
				end = i;
				break;
			}
		}
		int ans = 1;
		int cur = start;
		while(cur!=end){
			int nxt = 0;
			for(int i = cur+1; i<=min(cur+k,n-1); i++){
				if(s[i]=='*')nxt = i;
			}
			cur = nxt;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}