#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int cnt = 0;
		int cnt2 = 0;
		string s;
		cin >>s;
		string t;
		cin >> t;
		s = " " + s;
		t = " " + t;
		vector<pair<int,int>>arr(n+1);
		vector<pair<int,int>>arr2(n+1);
		for(int i = 1; i<=n; i++){
			if(s[i]!=s[i-1]&&s[i]=='1'){
				cnt++;
				arr[cnt] = {i,i};
			}
			else if(s[i]=='1'){
				arr[cnt].second++;
			}
			if(t[i]!=t[i-1]&&t[i]=='1'){
				cnt2++;
				arr2[cnt2] = {i,i};
			}
			else if(t[i]=='1'){
				arr2[cnt2].second++;
			}
		}
		if(cnt!=cnt2||s[1]!=t[1]||s[n]!=t[n]){
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		for(int i = 1; i<=cnt; i++){
			ans+=abs(arr[i].first-arr2[i].first);
			ans+=abs(arr[i].second-arr2[i].second);
		}
		cout << ans << "\n";
	}
	return 0;
}