#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <chrono>
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
const int offset = 10000;

int n, a[1005];
int dp[1005][20005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	dp[0][offset] = 1;
	int ret = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=2*offset; j++){
			if(j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
			if(j+a[i] <= 2 * offset) dp[i][j] += dp[i-1][j+a[i]];
			if(j == offset) dp[i][j]++;
			dp[i][j] %= mod;
		}
		ret += dp[i][offset];
		ret %= mod;
		ret += mod - 1;
		ret %= mod;
	}
	cout << ret;
}