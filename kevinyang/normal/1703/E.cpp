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
		vector<vector<int>>arr(n+1,vector<int>(n+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=n; j++){
				if(s[j-1]=='1')arr[i][j] = 1;
			}
		}
		int ans = 0;
		vector<vector<bool>>vis(n+1,vector<bool>(n+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(n%2==1&&i==j&&i*2==n+1)continue;
				if(vis[i][j])continue;
				int cnt = 0;
				cnt+=arr[i][j];
				cnt+=arr[n-j+1][i];
				cnt+=arr[n-i+1][n-j+1];
				cnt+=arr[j][n-i+1];
				ans+=min(cnt,4-cnt);
				vis[n-j+1][i] = true;
				vis[n-i+1][n-j+1] = true;
				vis[j][n-i+1] = true;
				//cout << cnt << "\n";
			}
		}
		cout << ans << "\n";
	}
	return 0;
}