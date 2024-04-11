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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, k, a[205];
int dp[205][205][1005];

int f(int pos, int stk, int lft){
	if(lft < 0) return 0;
	if(pos == 1) return stk == 0 || stk == 1;
	if(~dp[pos][stk][lft]) return dp[pos][stk][lft];
	int ret = 0;
	ret += f(pos - 1, stk + 1, lft - (stk + 1) * (a[pos] - a[pos-1]));
	ret %= mod;
	ret += f(pos - 1, stk, lft - stk * (a[pos] - a[pos-1]));
	ret %= mod;
	ret += 1ll * f(pos - 1, stk, lft - stk * (a[pos] - a[pos-1])) * stk % mod;
	ret %= mod;
	if(stk) ret += 1ll * f(pos - 1, stk - 1, lft - (stk - 1) * (a[pos] - a[pos-1])) * stk % mod;
	ret %= mod;
	return dp[pos][stk][lft] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	cout << f(n, 0, k);
}