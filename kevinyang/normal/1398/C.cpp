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
		map<int,int>hm;
		hm[0] = 1;
		int cur = 0;
		int ans = 0;
		for(int i = 0; i<n; i++){
			cur+=s[i]-'0'-1;
			ans+=hm[cur];
			hm[cur]++;
		}
		cout << ans << "\n";
	}
	return 0;
}