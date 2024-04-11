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
const int mod = 1e9 + 7;

int n, m;
char str[3005][3005];

int get(int sx, int sy, int ex, int ey){
	if(sx > ex || sy > ey) return 0;
	int dp[3005] = {};
	dp[sy] = 1;
	for(int i=sx; i<=ex; i++){
		for(int j=sy; j<=ey; j++){
			dp[j] += dp[j-1];
			dp[j] %= mod;
			if(str[i][j] == '#') dp[j] = 0;
		}
	}
	return dp[ey];
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%s",str[i]);
	}
	int t1 = get(0, 1, n-2, m-1);
	int t2 = get(0, 1, n-1, m-2);
	int t3 = get(1, 0, n-2, m-1);
	int t4 = get(1, 0, n-1, m-2);
	lint ret = 1ll * t1 * t4 % mod - (1ll * t2 * t3 % mod) + mod;
	printf("%lld",ret % mod);
}