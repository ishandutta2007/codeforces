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
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int dp[2005][2005];
int n, m, s;
int main(){
	cin >> n >> m;
	s = max(n, m);
	for(int i=1; i<=s; i++){
		int ds1 = 0, ds2 = 0;
		for(int j=2; j<=s; j++){
			ds1 += dp[i-1][j];
			ds2 += 1ll * dp[i-1][j] * (j - 1) % mod;
			ds1 %= mod, ds2 %= mod;
			dp[i][j] = mod + 1 + 1ll * ds1 * j % mod - ds2;
			dp[i][j] %= mod;
		}
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		int ds1 = 0, ds2 = 0;
		for(int j=2; j<=m; j++){
			int le = dp[i][j];
			int ri = 1 + 1ll * ds1 * j % mod + mod - ds2;
			ri %= mod;
			ds1 += dp[n-i][j];
			ds2 += 1ll * dp[n-i][j] * (j - 1) % mod;
			ds1 %= mod;
			ds2 %= mod;
			ret += (1ll * le * ri % mod) * (m - j + 1) % mod;
ret %= mod;
		}
	}
	cout << ret;
}