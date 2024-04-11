#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m;
int dp[505][505], sum[505][505];

int gs(int sx, int ex, int sy, int ey){
	return sum[ex][ey] - sum[sx-1][ey] - sum[ex][sy-1] + sum[sx-1][sy-1];
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d",&sum[i][j]);
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = gs(i, i, j, j);
		}
	}
	int ret = -1e9;
	for(int i=3; i<=n&&i<=m; i+=2){
		for(int j=1; j+i-1<=n; j++){
			for(int k=1; k+i-1<=m; k++){
				dp[j][k] = gs(j, j+i-1, k, k+i-1) - gs(j+1, j+1, k, k) - dp[j+1][k+1];
				ret = max(ret, dp[j][k]);
			}
		}
	}
	cout << ret;
}