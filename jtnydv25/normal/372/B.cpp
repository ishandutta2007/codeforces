#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))

const int N = 41;
int a[N][N], up[N][N];
int dp[N][N][N][N];
char s[N][N];
int main(){
	int n, m, q;
	sd(n); sd(m); sd(q);
	for(int i = 1; i <= n; i++)
			scanf("%s", s[i] + 1);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			up[i][j] = (s[i][j] == '0' ? up[i - 1][j] + 1 : 0);
		}
	}
	for(int l = 1; l <= m; l++){
		for(int r = l; r <= m; r++){
			for(int u = 1; u <= n; u++){
				for(int d = u; d <= n; d++){
					dp[u][l][d][r] = dp[u][l][d - 1][r];
					for(int lft = l; lft <= r; lft++){
						int mn = d - u + 1;
						for(int rgt = lft; rgt <= r; rgt++){
							mn = min(mn, up[d][rgt]);
							dp[u][l][d][r] += mn;
							if(!mn) break;
						}
					}
				}
			}
		}
	}

	while(q--){
		int a, b, c, d;
		sd(a) ; sd(b); sd(c); sd(d);
		printf("%d\n", dp[a][b][c][d]);
	}
}