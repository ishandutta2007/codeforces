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

int n, a[100005];
int dp[100005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		int t;
		cin >> t;
		a[t] = i;
	}
	dp[1] = 1;
	for(int i=2; i<=n; i++){
		if(i>1 && a[i-1] < a[i]) dp[i] = dp[i-1] + 1;
		else dp[i] = 1;
	}
	cout << n - *max_element(dp, dp + n + 1);
}