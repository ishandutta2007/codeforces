#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 105;

int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN][10005];

int main(){
	cin >> n;
	int sumB = 0;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i];
		sumB += b[i];
	}
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			for(int k=0; k<=10004; k++) dp[i][j][k] = -1e9;
		}
	}
	dp[0][0][0] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=n; j++){
			for(int k=0; k<=10000; k++){
				dp[i][j][k] = dp[i-1][j][k];
				if(j && k >= a[i]){
					dp[i][j][k] = max(dp[i][j][k], 
					dp[i-1][j - 1][k - a[i]] + b[i]);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		double ret = 0;
		for(int j=0; j<=10000; j++){
			ret = max(ret, min(1.0 * j, (dp[n][i][j] + sumB) * 0.5));
		}
		printf("%.10f ", ret);
	}
}