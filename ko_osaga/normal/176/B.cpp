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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, k;
int dp[1005];
string s, t;

int main(){
	cin >> s >> t >> k;
	n = s.size();
	dp[0] = 1;
	for(int i=1; i<=k; i++){
		int s = 0;
		for(int j=0; j<n; j++){
			s += dp[j];
			s %= mod;
		}
		for(int j=0; j<n; j++){
			dp[j] = mod + s - dp[j];
			dp[j] %= mod;
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		if(s == t){
			ret += dp[i];
			ret %= mod;
		}
		rotate(s.begin(), s.begin() + 1, s.end());
	}
	printf("%d\n",ret);
}