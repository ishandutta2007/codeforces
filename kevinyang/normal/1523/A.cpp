#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int>dis(n+2,(int)1e18);
		vector<int>dis2(n+2,(int)1e18);
		vector<int>ans(n+1);
		if(true){
			int cur = (int)1e18;
			for(int i = 1; i<=n; i++){
				cur++;
				if(s[i-1]=='1')cur = 0;
				dis[i] = min(dis[i],cur);
			}
		}
		if(true){
			int cur = (int)1e18;
			for(int i = n; i>=1; i--){
				cur++;
				if(s[i-1]=='1')cur = 0;
				dis2[i] = min(dis2[i],cur);
			}
		}
		for(int i = 1; i<=n; i++){
			cout << (((dis[i]<=m||dis2[i]<=m)&&dis[i]!=dis2[i])||s[i-1]=='1');
		}
		cout << "\n";
	}
	return 0;
}