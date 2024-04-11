#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

lint dp[44][44][44][44];
int sum[44][44];

int n, m, q;

int getsum(int sx, int ex, int sy, int ey){
	return sum[ex][ey] - sum[sx-1][ey] - sum[ex][sy-1] + sum[sx-1][sy-1];
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0; i<n; i++){
		char buf[55];
		scanf("%s",buf);
		for(int j=0; j<m; j++){
			if(buf[j] == '1'){
				sum[i+1][j+1]++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			for(int k=1; k<=m; k++){
				for(int l=k; l<=m; l++){
					if(getsum(i, j, k, l) == 0){
						dp[i][k][j][l]++; // (i, k) / (j, l)
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=n; k; k--){
				for(int l=m; l; l--){
					dp[k][l][i][j] += dp[k+1][l][i][j] + dp[k][l+1][i][j] - dp[k+1][l+1][i][j];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=1; k<=n; k++){
				for(int l=1; l<=m; l++){
					dp[i][j][k][l] += dp[i][j][k-1][l] + dp[i][j][k][l-1] - dp[i][j][k-1][l-1];
				}
			}
		}
	}
	for(int i=1; i<=q; i++){
		int sx, sy, ex, ey;
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		printf("%lld\n",dp[sx][sy][ex][ey]);
	}
}