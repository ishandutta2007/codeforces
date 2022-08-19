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
const int mod = 1e9 + 9;

int n, m, k;
lint a[5005], dp[5005][5005];

lint f(int x, int y){
	if(x == 0) return y == 0 ? 0 : -1e18;
	if(~dp[x][y]) return dp[x][y];
	lint ret = f(x-1, y);
	if(x >= m) ret = max(ret, f(x-m, y-1) + a[x] - a[x-m]);
	return dp[x][y] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	cout << f(n, k);
}