#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int arr[1005][1005], dp[1005][1005];
int rmq[10][10][1005][1005];
int lg[1005], n, m;

int query(int sx, int ex, int sy, int ey){
	int l1 = lg[ex-sx+1];
	int l2 = lg[ey-sy+1];
	return max({rmq[l1][l2][sx][sy], rmq[l1][l2][ex-(1<<l1)+1][sy],
			rmq[l1][l2][sx][ey-(1<<l2)+1], rmq[l1][l2][ex-(1<<l1)+1][ey-(1<<l2)+1]});
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=n; i; i--){
		for(int j=m; j; j--){
			dp[i][j] = min({dp[i][j+1], dp[i+1][j+1], dp[i+1][j]}) + 1;
			if(arr[i][j] == 0) dp[i][j] = 0;
			rmq[0][0][i][j] = dp[i][j];
		}
	}
	for(int i=1; i<=1004; i++){
		lg[i] = lg[i-1];
		while((2 << lg[i]) <= i) lg[i]++;
	}
	for(int i=0; i<10; i++){
		if(i){
			for(int k=1; k<=n; k++){
				for(int l=1; l<=m; l++){
					rmq[i][0][k][l] = rmq[i-1][0][k][l];
					if(k +(1<<(i-1)) <= n){
						rmq[i][0][k][l] = max(rmq[i][0][k][l], rmq[i-1][0][k+(1<<(i-1))][l]);
					}
				}
			}
		}
		for(int j=1; j<10; j++){
			for(int k=1; k<=n; k++){
				for(int l=1; l<=m; l++){
					rmq[i][j][k][l] = rmq[i][j-1][k][l];
					if(l + (1<<(j-1))<= m){
						rmq[i][j][k][l] = max(rmq[i][j][k][l],rmq[i][j-1][k][l +(1<<(j-1))]);
					}
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int sx, ex, sy, ey;
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		int s = 0, e = min(ey-sy+1, ex-sx+1);
		while(s != e){
			int m = (s+e+1)/2;
			if(query(sx, ex-m+1, sy, ey-m+1) >= m) s = m;
			else e = m-1;
		}
		printf("%d\n", s);
	}
}