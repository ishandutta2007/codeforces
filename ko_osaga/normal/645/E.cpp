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
string s;
int locc[26];
int nxt[26], dp[2000005];

int main(){
	cin >> n >> k >> s;
	memset(locc, -1, sizeof(locc));
	for(int i=0; i<s.size(); i++){
		locc[s[i] - 'a'] = i;
	}
	int m = s.size();
	for(int i=0; i<n; i++){
		int p = min_element(locc, locc + k) - locc;
		s.push_back(p + 'a');
		locc[p] = i + m;
	}
	for(int i=0; i<k; i++){
		nxt[i] = s.size();
	}
	for(int i=s.size()-1; i>=0; i--){
		dp[i] = 1;
		for(int j=0; j<k; j++){
			if(nxt[j] != s.size()) dp[i] += dp[nxt[j]];
			dp[i] %= mod;
		}
		for(int j=0; j<k; j++){
			if(s[i] == j + 'a') nxt[j] = i;
		}
	}
	int ret = 1;
	for(int i=0; i<k; i++){
		if(nxt[i] != s.size()) ret += dp[nxt[i]];
		ret %= mod;
	}
	cout << ret;
}