#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s,t;
		cin >> s >> t;
		int n = s.length(); int m = t.length();
		vector<vector<vector<bool>>>dp(m+5,vector<vector<bool>>(m+5,vector<bool>(m+5)));
		s = " " + s;
		t = " " + t;
		int b = 1000;
		vector<queue<int>>arr(26);
		for(int i = 1; i<=m; i++){
			dp[0][i][i-1] = true;
			arr[t[i]-'a'].push(0*b*b+i*b+i);
			if(i>1)arr[t[1]-'a'].push(1*b*b+i*b+i-1);
		}
		for(int i = 1; i<=n; i++){
			vector<queue<int>>q(26);
			while(arr[s[i]-'a'].size()){
				int nxt = arr[s[i]-'a'].front(); arr[s[i]-'a'].pop();
				int x = nxt/b/b; int y = (nxt%(b*b))/b; int z = nxt%b;
				if(dp[x][y][z])continue;
				//cerr << x << " " << y << " " << z << "\n";
				dp[x][y][z] = true;
				if(z+1<=m){
					q[t[z+1]-'a'].push(x*b*b+y*b+z+1);
				}
				if(x+1<=m&&x+1<y){
					q[t[x+1]-'a'].push((x+1)*b*b+y*b+z);
				}
			}
			for(int i = 0; i<26; i++){
				while(q[i].size()){
					int nxt = q[i].front(); q[i].pop();
					arr[i].push(nxt);
				}
			}
		}
		bool f = false;
		for(int i = 0; i<m; i++){
			if(dp[i][i+1][m])f = true;
		}
		if(dp[0][1][m])f = true;
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}