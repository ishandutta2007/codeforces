#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
using lint = long long;
const int mod = 998244353;
const int MAXN = 2000005;

int n, a, b;
char str[MAXN];
lint dp[MAXN][2];

int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&a,&b);
		scanf("%s", str + 1);
		dp[0][1] = 1e18;
		dp[0][0] = b;
		for(int i=1; i<=n; i++){
			if(str[i] == '1'){
				dp[i][0] = 1e18;
				dp[i][1] = dp[i-1][1] + 2 * b + a;
			}
			else{
				dp[i][0] = min(dp[i-1][0] + a, dp[i-1][1] + 2 * a) + b;
				dp[i][1] = min(dp[i-1][0] + 2 * a, dp[i-1][1] + a) + 2 * b;
			}
		}
		cout << dp[n][0] << endl;
	}
}