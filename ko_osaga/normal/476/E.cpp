#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 9;
const int MAXN = 300005;

int n, m;
char a[2005], b[2005];
int fail[505];
int dp[2005][2005];

int main(){
	cin >> a >> b;
	n = strlen(a);
	m = strlen(b);
	int p = 0;
	for(int i=1; b[i]; i++){
		while(p && b[p] != b[i]) p = fail[p];
		if(b[p] == b[i]) p++;
		fail[i+1] = p;
	}
	for(int i=1; i<=n; i++) dp[0][i] = -1e9;
	for(int i=1; i<=n; i++){
		int p = i, ma = 0;
		while(p > 0 && ma < m){
			if(a[p-1] == b[m-ma-1]) ma++;
			p--;
		}
		for(int j=0; j<=n; j++){
			dp[i][j] = dp[i-1][j];
			if(j > 0) dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
			if(ma == m && j - m >= 0) dp[i][j] = max(dp[i][j], dp[p][j-m] + 1);
		}
	}
	for(int i=n; i>=0; i--) printf("%d ", dp[n][i]);
}