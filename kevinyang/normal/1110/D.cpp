#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>dp(7,vector<int>(7,-(int)1e8));
	vector<vector<int>>dp2(7,vector<int>(7,-(int)1e8));
	dp[0][0] = 0;
	vector<int>freq(m+1);
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		freq[x]++;
	}
	int ans = 0;
	int total = 0;
	for(int i = 1; i<=m; i++){
		if(freq[i]==0){
			total+=ans;
			ans = 0;
			for(int a = 0; a<=6; a++){
				for(int b = 0; b<=6; b++){
					dp[a][b] = dp2[a][b] = -(int)1e8;
					dp[0][0] = 0;
				}
			}
		}
		for(int a = 0; a<=6; a++){
			for(int b = 0; b<=6; b++){
				for(int r = 0; r<=2; r++){
					if(r>a||r>b)break;
					if(r>freq[i])break;
					int rem = (freq[i]-r)%3;
					for(int c = 0; c<3; c++){
						if(rem+c*3>6)continue;
						if(rem+c*3>freq[i]-r)continue;
						dp2[b-r][rem+c*3] = max(dp2[b-r][rem+c*3],dp[a][b]+r+(freq[i]-r)/3-c);
					}
				}
			}
		}
		//cerr << "nae\n";
		for(int a = 0; a<=6; a++){
			for(int b = 0; b<=6; b++){
				//cout << dp2[a][b] << " ";
				dp[a][b] = dp2[a][b];
				dp2[a][b] = -(int)1e8;
				ans = max(ans,dp[a][b]);
			}
			//cout << "\n";
		}
		//cout << "\n";
	}
	total+=ans;
	cout << total << "\n";
	return 0;
}