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

string s;
int dp[105];
int n, p, q;

void bktk(int x){
	if(x == 0) return;
	if(x >= p && dp[x-p] == dp[x] - 1){
		bktk(x-p);
		cout << s.substr(x-p, p) << endl;
		return;
	}
	bktk(x-q);
	cout << s.substr(x-q, q) << endl;
}

int main(){
	cin >> n >> p >> q >> s;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		if(i >= p) dp[i] = min(dp[i], dp[i-p] + 1);
		if(i >= q) dp[i] = min(dp[i], dp[i-q] + 1);
	}
	if(dp[n] > 1e9){
		cout << -1;
		return 0;
	}
	cout << dp[n] << endl;
	bktk(n);
}