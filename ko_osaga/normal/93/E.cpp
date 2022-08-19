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
typedef pair<double, double> pi;

lint n;
int k, a[105];
lint dp[105][300005];

lint bktk(int x, lint p){
	if(p == 0) return 0;
	if(x == k) return p;
	if(p <= 300000 && ~dp[x][p]) return dp[x][p];
	lint ret = bktk(x+1, p) - bktk(x+1, p / a[x]);
	if(p <= 300000) dp[x][p] = ret;
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for(int i=0; i<k; i++){
		cin >> a[i];
	}
	sort(a, a+k);
	reverse(a, a+k);
	cout << bktk(0, n);
}