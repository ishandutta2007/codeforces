#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 5005;

int n, a[MAXN];
int dp[MAXN][MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++){
		dp[i][i] = a[i];
	}
	for(int i=1; i<n; i++){
		for(int j=0; j+i<n; j++){
			dp[j][j+i] = (dp[j][j+i-1] ^ dp[j+1][j+i]);
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j+i<n; j++){
			dp[j][j+i] =
			max({dp[j][j+i-1], dp[j][j+i], dp[j+1][j+i]});
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int l, r;
		scanf("%d %d",&l,&r);
		printf("%d\n", dp[l-1][r-1]);
	}
}