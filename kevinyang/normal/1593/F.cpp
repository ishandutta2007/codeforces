#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,A,B;
		cin >> n >> A >> B;
		string s;
		cin >> s;
		vector<int>arr(n+1);
		
		for(int i = 1; i<=n; i++){
			arr[i] = s[i-1]-'0';
		}
		
		//cerr << "nae\n";
		int dp[n+1][A+1][B+1][n+1];
		int prev[n+1][A+1][B+1][n+1];
		memset(dp,0,sizeof(dp));
		memset(prev,0,sizeof(prev));
		dp[0][0][0][0] = 1;
		//cerr << "nae2\n";
		
		for(int t = 1; t<=n; t++){
			for(int a = 0; a<A; a++){
				for(int b = 0; b<B; b++){
					for(int k = 0; k<t; k++){
						if(dp[t-1][a][b][k]>0){
							dp[t][(a*10+arr[t])%A][b][k+1] = 1;
							prev[t][(a*10+arr[t])%A][b][k+1] = a;
							dp[t][a][(b*10+arr[t])%B][k] = 2;
							prev[t][a][(b*10+arr[t])%B][k] = b;
						}
					}
				}
			}
		}
		int mn = (int)1e18;
		int a = 0; int b = 0; int k = 0;
		for(int i = 0; i<=n; i++){
			if(dp[n][0][0][i]>=1){
				if(abs(n-2*i)<mn){
					mn = abs(n-2*i);
					k = i;
				}
			}
		}
		if(mn==(int)1e18||mn==n){
			cout << "-1\n";
			continue;
		}
		string ans = "";
		for(int i = n; i>=1; i--){
			if(dp[i][a][b][k]==1){
				ans+="R";
				a = prev[i][a][b][k]; k--;
			}
			else{
				ans+="B";
				b = prev[i][a][b][k];
			}
		}
		reverse(ans.begin(),ans.end());
		cout << ans << "\n";
		
	}
	return 0;
}