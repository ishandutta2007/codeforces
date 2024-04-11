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

int n;
pi a[2005];
lint dp[2005][2005];

lint f(int pos, int cap){
	cap = min(cap, n);
	if(pos == n) return cap < n ? 1e18 : 0;
	if(~dp[pos][cap]) return dp[pos][cap];
	lint ret = 1e18;
	ret = min(ret, f(pos + 1, cap + 1 + a[pos].first) + a[pos].second);
	ret = min(ret, f(pos + 1, cap));
	return dp[pos][cap] = ret;
}

// k robbery  ,   cost?

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	lint ret = f(0, 0);
	cout << ret;
}