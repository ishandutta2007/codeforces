#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXL = 255;
using lint = long long;
using pi = pair<int, int>;

int n, q;
char str[MAXN];
int nxt[MAXN][26];
int dp[MAXL][MAXL][MAXL];
char chr[3][MAXL];
int sz[3];

int main(){
	scanf("%d %d",&n,&q);
	scanf("%s", str);
	for(int i=0; i<26; i++){
		nxt[n][i] = n;
		for(int j=n-1; j>=0; j--){
			if(str[j] == i + 'a') nxt[j][i] = j;
			else nxt[j][i] = nxt[j+1][i];
		}
	}
	while(q--){
		char b1[5], b2[5];
		int x;
		scanf("%s %d",b1,&x);
		x--;
		if(*b1 == '+'){
			scanf("%s", b2);
			chr[x][sz[x]++] = *b2 - 'a';
			for(int i=(x==0?sz[0]:0); i<=sz[0]; i++){
				for(int j=(x==1?sz[1]:0); j<=sz[1]; j++){
					for(int k=(x==2?sz[2]:0); k<=sz[2]; k++){
						dp[i][j][k] = 1e9;
						if(i > 0 && dp[i-1][j][k] < n &&  nxt[ dp[i-1][j][k] ][ chr[0][i-1] ] < n){
							dp[i][j][k] = min(dp[i][j][k], nxt[ dp[i-1][j][k] ][ chr[0][i-1] ] + 1);
						}
						if(j > 0 && dp[i][j-1][k] < n && nxt[ dp[i][j-1][k] ][ chr[1][j-1] ] < n){
							dp[i][j][k] = min(dp[i][j][k], nxt[ dp[i][j-1][k] ][ chr[1][j-1] ] + 1);
						}
						if(k > 0 && dp[i][j][k-1] < n &&  nxt[ dp[i][j][k-1] ][ chr[2][k-1] ] < n){
							dp[i][j][k] = min(dp[i][j][k], nxt[ dp[i][j][k-1] ][ chr[2][k-1] ] + 1);
						}
					}
				}
			}
		}
		else{
			sz[x]--;
		}
		if(dp[sz[0]][sz[1]][sz[2]] <= n) puts("YES");
		else puts("NO");
	}
}