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

int dp[1<<24];
int a[24], n;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int k, t[2] = {-1, -1};
	cin >> k;
	for(int i=0; i<k; i++) cin >> t[i];
	dp[0] = 1;
	for(int i=1; i<(1<<n); i++){
		lint ret = 0, sum = 0;
		for(int j=0; j<n; j++){
			if((i >> j) & 1){
				ret += dp[i^(1<<j)];
				sum += a[j];
			}
		}
		if(sum != t[0] && sum != t[1]) dp[i] = ret % mod;
	}
	cout << dp[(1<<n)-1];
}