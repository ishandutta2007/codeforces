#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, k, a[505];
int dp[2][505][505];

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	dp[0][0][0] = 1;
	for(int i=1; i<=n; i++){
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		for(int j=0; j<=k; j++){
			for(int l=0; l<=k; l++){
				dp[i%2][j][l] = dp[(i-1)%2][j][l];
				if(j >= a[i]){
					dp[i%2][j][l] |= dp[(i-1)%2][j-a[i]][l];
				}
				if(j >= a[i] && l >= a[i]){
					dp[i%2][j][l] |= dp[(i-1)%2][j-a[i]][l-a[i]];
				}
			}
		}
	}
	vector<int> ret;
	for(int i=0; i<=k; i++){
		if(dp[n%2][k][i]) ret.push_back(i);
	}
	printf("%d\n", ret.size());
	for(auto &i : ret) printf("%d ", i);
}