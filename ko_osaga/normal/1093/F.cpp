#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;
const int mod = 998244353; // I hate this modulo!

int n, k, l, a[MAXN];
lint dp[MAXN][105], tot[MAXN], BEZE[MAXN][105];
lint WEIRDSUM[MAXN][105];
lint BTOT[MAXN];

int sum[MAXN][105];
int nxt[MAXN][105];

int main(){
	scanf("%d %d %d",&n,&k,&l);
	for(int i=2; i<=n+1; i++) scanf("%d",&a[i]);
	if(l == 1){
		cout << 0 << endl;
		return 0;
	}
	for(int i=0; i<=k; i++){
		for(int j=1; j<=n+2; j++){
			sum[j][i] = sum[j-1][i];
			if(a[j] != i && a[j] != -1) sum[j][i]++;
		}
	}
	for(int i=0; i<=k; i++){
		for(int j=1; j<=n+2; ){
			int e = j;
			while(e <= n + 2 && sum[e-1][i] == sum[j-1][i]) e++;
			for(int k=j; k<e; k++) nxt[k][i] = e;
			j = e;
		}
	}
	dp[n+2][0] = 1;
	tot[n+2] = 1;
	for(int i=1; i<=k; i++) WEIRDSUM[n+2][i] = 1;
	for(int i=n+1; i; i--){
		for(int j=0; j<=k; j++){
			if(a[i] != -1 && a[i] != j){
				dp[i][j] = 0;
			}
			else if(a[i] == -1 && j == 0){
				dp[i][j] = 0;
			}
			else{
				int x = nxt[i][j];
				x = max(x, i + l);
				dp[i][j] = tot[i+1];
				dp[i][j] += mod - (BTOT[i+1] - BEZE[i+1][j]);
				BEZE[i][j] = WEIRDSUM[i+l][j] - WEIRDSUM[x][j] + mod;
				BEZE[i][j] %= mod;
				dp[i][j] %= mod;
			}
			tot[i] += dp[i][j];
			BTOT[i] += BEZE[i][j];
			BTOT[i] %= mod;
			tot[i] %= mod;
		}
		for(int j=0; j<=k; j++){
			WEIRDSUM[i][j] = WEIRDSUM[i+1][j] + (tot[i] - dp[i][j] - BTOT[i] + BEZE[i][j]) + 2 * mod;
			WEIRDSUM[i][j] %= mod;
		}
	}
	cout << dp[1][0] << endl;
}