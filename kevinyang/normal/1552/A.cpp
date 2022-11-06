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
		string t = s;
		sort(t.begin(),t.end());
		int cnt = 0;
		for(int i = 0; i<n; i++){
			if(s[i]!=t[i])cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}