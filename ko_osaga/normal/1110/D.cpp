#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n, m;
int dp[MAXN][3][3], cnt[MAXN];

int main(){
	scanf("%d %d",&m,&n);
	while(m--){
		int x; scanf("%d",&x);
		cnt[x]++;
	}
	int dap = 0;
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				dp[i][j][k] = -1e9;
			}
		}
	}
	dp[1][0][0] = 0;
	for(int i=1; i<=n; i++){
		// [i - 2, i]
		// [i - 1, i + 1]
		// [i, ??]
		for(int j=0; j<=2; j++){
			for(int k=0; k<=2; k++){
				for(int l=0; l<=2; l++){
					if(j + k + l > cnt[i]) continue;
					dp[i+1][k][l] = max(dp[i][j][k] + l + (cnt[i] - j - k - l) / 3, dp[i+1][k][l]);
				}
			}
		}
	}
	cout << dp[n+1][0][0] + dap << endl;
}