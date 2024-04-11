#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 2005;
const int mod = 1e9 + 7;
#define sz(v) ((int)(v).size())

int n, m;
char str[MAXN][MAXN];
lint dp[MAXN][MAXN][2];
lint sum[MAXN][MAXN][2];

void push(int x, int y, int d, int v){
	if(x < n && y < m){
		dp[x][y][d] += v;
		if(dp[x][y][d] >= mod) dp[x][y][d] -= mod;
	}
}

int R[MAXN][MAXN];
int D[MAXN][MAXN];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%s", str[i]);
	if(str[n-1][m-1] == 'R'){
		cout << 0 << endl;
		return 0;
	}
	if(n * m == 1){
		cout << 1 << endl;
		return 0;
	}
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			R[i][j] = (str[i][j] == 'R') + R[i][j + 1];
			D[i][j] = (str[i][j] == 'R') + D[i + 1][j];
		}
	}
	push(0, 0, 0, 1);
	push(0, 0, 1, 1);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i > 0) sum[i][j][0] += sum[i-1][j][0];
			if(j > 0) sum[i][j][1] += sum[i][j-1][1];
			sum[i][j][0] %= mod;
			sum[i][j][1] %= mod;
			dp[i][j][0] += sum[i][j][0];
			dp[i][j][1] += sum[i][j][1];
			dp[i][j][0] %= mod;
			dp[i][j][1] %= mod;
			int loMax = n - D[i + 1][j];
			int riMax = m - R[i][j + 1];
			sum[i+1][j][0] += dp[i][j][1];
			sum[loMax][j][0] += mod - dp[i][j][1];
			sum[i][j+1][1] += dp[i][j][0];
			sum[i][riMax][1] += mod - dp[i][j][0];
		}
	}
	cout << (dp[n-1][m-1][0] + dp[n-1][m-1][1]) % mod << endl;
}