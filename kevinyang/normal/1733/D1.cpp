#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x,y;
		cin >> n >> x >> y;
		string s,s2;
		cin >> s >> s2;
		vector<int>a(n+1);
		for(int i = 1; i<=n; i++){
			if(s[i-1]!=s2[i-1]){
				a[i] = 1;
			}
		}
		if(count(a.begin(),a.end(),1)%2==1){
			cout << "-1\n";
			continue;
		}
		vector<int>idx;
		for(int i = 1; i<=n; i++){
			if(a[i])idx.push_back(i);
		}
		int m = idx.size()/2;
		int ans = 0;
		for(int i = 0; i<m; i++){
			int v = idx[i];
			int v2 = idx[i+m];
			if(abs(v-v2)==1){
				ans+=min(2*y,x);
			}
			else{
				ans+=y;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}