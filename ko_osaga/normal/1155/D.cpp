#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e6 + 3;
const int MAXN = 300005;

lint dp[MAXN][3][3];
int n, x, a[MAXN];


int main(){
	scanf("%d %d",&n,&x);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i + j != 0) dp[0][i][j] = -1e18;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				dp[i][j][k] = -1e18;
				for(int l=0; l<=j; l++){
					for(int m=0; m<=k; m++){
						dp[i][j][k] = max(dp[i][j][k], dp[i-1][l][m]);
					}
				}
				if(j == 1){
					lint cur = a[i];
					if(k == 1) cur *= x;
					dp[i][j][k] += cur;
				}
			}
		}
	}
	lint ret = 0;
	for(int i=0; i<3; i++) for(int j=0; j<3; j++) ret = max(ret, dp[n][i][j]);
	cout << ret << endl;
}