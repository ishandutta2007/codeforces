#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int>arr(250);
		string a;
		cin >> a;
		for(int i = 0; i<26; i++){
			arr[a[i]] = i;
		}
		string s;
		cin >> s;
		int ans = 0;
		for(int i = 1; i<s.length(); i++){
			ans+=abs(arr[s[i]]-arr[s[i-1]]);
		}
		cout << ans << "\n";
	}
	return 0;
}