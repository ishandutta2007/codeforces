#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
const int mod1 = 1e9 + 409;
const int mod2 = 1e9 + 433;
typedef long long lint;
using pi = pair<lint, lint>;

int n, k, p, a[MAXN];
int dp[55][MAXN];

int main(){
	scanf("%d %d %d",&n,&k,&p);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i] += a[i-1];
		a[i] %= p;
	}
	fill(dp[0] + 1, dp[0] + n + 1, -1e9);
	for(int i=1; i<=k; i++){
		int cmax[105] ={};
		fill(cmax, cmax + 105, -1e9);
		for(int j=1; j<=n; j++){
			cmax[a[j-1]] = max(cmax[a[j-1]], dp[i-1][j-1]);
			dp[i][j] = -1e9;
			for(int k=0; k<p; k++){
				dp[i][j] = max(dp[i][j], cmax[k] + (k > a[j]));
			}
		}
	}
	cout << dp[k][n] * p + a[n];
}