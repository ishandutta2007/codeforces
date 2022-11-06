#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>nextnum(n+2); nextnum[n+1] = n+1; nextnum[0] = n+1;
	vector<int>arr(n+1);
	vector<int>freq(100001); int cnt2 = 0;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int cur = 0;
	//vector<vector<int>>adj(n+1);
	for(int i = 1; i<=n; i++){
		while(cur<=n&&cnt2==0){
			cur++;
			if(cur==n+1)break;
			int k = arr[cur];
			for(int j = 2; j*j<=arr[cur]; j++){
				if(k%j==0){
					freq[j]++; if(freq[j]==2)cnt2++;
				}
				while(k%j==0){
					k/=j;
				}
			}
			if(k>1){
				freq[k]++;
				if(freq[k]==2)cnt2++;
			}
		}
		nextnum[i] = cur;
		if(true){
			int k = arr[i];
			for(int j = 2; j*j<=arr[i]; j++){
				if(k%j==0){
					freq[j]--; if(freq[j]==1)cnt2--;
				}
				while(k%j==0){
					k/=j;
				}
			}
			if(k>1){
				freq[k]--;
				if(freq[k]==1)cnt2--;
			}
		}
		assert(i<nextnum[i]);
		//cerr << i << " " << nextnum[i] << "\n";
	}
	int ln = 20;
	vector<vector<int>>dp(n+2,vector<int>(ln));
	for(int i = 0; i<ln; i++){
		dp[n+1][i] = n+1; dp[0][i] = n+1;
	}
	for(int i = n; i>=1; i--){
		dp[i][0] = nextnum[i];
		for(int j = 1; j<ln; j++){
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<ln; j++){
			assert(dp[i][j]);
		}
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		int dis = 0;
		int k = l;
		for(int i = ln-1; i>=0; i--){
			if(dp[k][i]>r)continue;
			dis+=(1<<i);
			k = dp[k][i];
		}
		cout << dis+1 << "\n";
	}
	return 0;
}