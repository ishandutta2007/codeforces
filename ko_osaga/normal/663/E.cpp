#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m, dp[2][21][1<<20];
int a[100005];
char str[100005];

int main(){
	scanf("%d %d",&m,&n);
	for(int i=0; i<m; i++){
		scanf("%s", str);
		for(int j=0; j<n; j++){
			if(str[j] == '1') a[j] |= (1 << i);
		}
	}
	for(int i=0; i<n; i++) dp[0][0][a[i]]++;
	for(int i=0; i<m; i++){
		int prv = i % 2, nxt = (i + 1) % 2;
		memset(dp[nxt], 0, sizeof(dp[nxt]));
		for(int j=0; j<=m; j++){
			for(int k=0; k<(1<<m); k++){
				dp[nxt][j][k] = dp[prv][j][k] + (j > 0 ? dp[prv][j-1][k ^ (1<<i)] : 0);
			}
		}
	}
	int ret = 1e9;
	for(int i=0; i<(1<<m); i++){
		int ans = 0;
		int tmp = 0;
		for(int j=0; j<=m; j++){
			ans += dp[m%2][j][i] * min(j, m - j);
			tmp += dp[m%2][j][i];
		}
		ret = min(ret, ans);
	}
	cout << ret;
}