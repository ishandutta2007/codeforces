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
		string ans;
		for(int i = 0; i<2*n; i+=2){
			ans+=s[i];
		}
		cout << ans << "\n";
	}
	return 0;
}