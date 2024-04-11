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

int n;
int dp[10005][4], ok[10005];
string s;

int f(int x, int y){
	if(x == n) return 1;
	if(~dp[x][y]) return dp[x][y];
	for(int i=2; i<=3; i++){
		if(x + i > n) break;
		if(s.substr(x-y, y) == s.substr(x, i)){
			continue;
		}
		if(f(x+i, i)) return dp[x][y] = 1;
	}
	return dp[x][y] = 0;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> s;
	n = s.size();
	for(int i=5; i<n; i++){
		ok[i] = f(i, 0);
	}
	set<string> ret;
	for(int i=5; i<n; i++){
		for(int j=2; j<=3 && i + j <= n; j++){
			if(f(i+j, j)) ret.insert(s.substr(i, j)); 
		}
	}
	cout << ret.size() << endl;
	for(auto &i : ret){
		cout << i << endl;
	}
}