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

string s, t;
int dp[5005][5005];

int main(){
	cin >> s >> t;
	for(int i=s.size(); i>=0; i--){
		dp[i][t.size()] = 1;
		for(int j=t.size()-1; j>=0; j--){
			if(i == s.size()){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i][j+1];
			if(s[i] == t[j]) dp[i][j] += dp[i+1][j+1];
			dp[i][j] %= mod;
		}
	}
	lint ret = 0;
	for(int i=0; i<s.size(); i++){
		ret += dp[i][0] + mod - 1;
	}
	cout << ret % mod;
}