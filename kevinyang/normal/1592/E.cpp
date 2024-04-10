#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Sparse{
	vector<int>logs;
	vector<vector<int>>dp;
	int ln;
	int size;
	void init(int n, vector<int>arr){
		size = n;
		logs.resize(n+1);
		dp.resize(n+1);
		ln = 0;
		for(int i = 1; i<=n; i*=2){
			logs[i] = ln; ln++;
		}
		for(int i = 1; i<=n; i++){
			dp[i].resize(ln+1);
			logs[i] = max(logs[i],logs[i-1]);
			dp[i][0] = arr[i];
		}
		for(int i = 1; i<=ln; i++){
			for(int j = 1; j+(1<<i)-1<=n; j++){
				dp[j][i] = (dp[j][i-1]&dp[j+(1<<(i-1))][i-1]);
			}
		}
	}
	int query(int l, int r){
		int lg = logs[r-l+1];
		return (dp[l][lg]&dp[r-(1<<lg)+1][lg]);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	Sparse sparse;
	sparse.init(n,arr);
	for(int i = 20; i>=0; i--){
		int change = (1<<25)-(1<<i);
		vector<int>arr2(n+1);
		for(int i = 1; i<=n; i++){
			arr2[i] = arr[i]&change;
		}
		if(true){
			vector<bool>vis(2000005);
			vector<int>dp(2000005);
			vis[0] = true;
			vector<int>rem;
			rem.push_back(0);
			int cur = 0;
			for(int j = 2; j<=n; j+=2){
				cur^=arr2[j-1]^arr2[j];
				if((arr2[j]&(1<<i))&&(arr2[j-1]&(1<<i))){
					if(vis[cur]){
						int idx = dp[cur];
						if((sparse.query(idx+1,j)&change)!=(1<<i)){
							continue;
						}
						else{
							ans = max(ans,j-idx);
						}
					}
					else{
						vis[cur] = true;
						dp[cur] = j;
						rem.push_back(cur);
					}
				}
				else{
					for(int nxt: rem){
						vis[nxt] = false;
						dp[nxt] = 0;
					}
					rem.clear();
					vis[cur] = true;
					dp[cur] = j;
					rem.push_back(cur);
				}
			}
		}
		if(true){
			vector<bool>vis(2000005);
			vector<int>dp(2000005);
			vis[arr[1]] = true;
			vector<int>rem;
			rem.push_back(arr[1]);
			dp[arr[1]] = 1;
			int cur = arr[1];
			for(int j = 3; j<=n; j+=2){
				cur^=arr2[j-1]^arr2[j];
				if((arr2[j]&(1<<i))&&(arr2[j-1]&(1<<i))){
					if(vis[cur]){
						int idx = dp[cur];
						if((sparse.query(idx+1,j)&change)!=(1<<i)){
							continue;
						}
						else{
							ans = max(ans,j-idx);
						}
					}
					else{
						vis[cur] = true;
						dp[cur] = j;
						rem.push_back(cur);
					}
				}
				else{
					for(int nxt: rem){
						vis[nxt] = false;
						dp[nxt] = 0;
					}
					rem.clear();
					vis[cur] = true;
					dp[cur] = j;
					rem.push_back(cur);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}