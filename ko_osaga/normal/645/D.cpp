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

vector<int> gph[100005];
int n, m, s[100005], e[100005];
int dp[100005];

int f(int x){
	if(~dp[x]) return dp[x];
	int ret = 0;
	for(auto &i : gph[x]){
		ret = max(ret, f(i));
	}
	return dp[x] = ret + 1;
}

int trial(int x){
	for(int i=1; i<=n; i++){
		gph[i].clear();
	}
	for(int i=0; i<x; i++){
		gph[s[i]].push_back(e[i]);
	}
	int ret = 0;
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=n; i++){
		ret = max(ret, f(i));
	}
	return ret == n;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> s[i] >> e[i];
	}
	int s = 0, e = m;
	while(s != e){
		int mid = (s+e)/2;
		if(trial(mid)) e = mid;
		else s = mid + 1;
	}
	if(trial(s) == 0){
		puts("-1");
	}
	else{
		printf("%d",s);
	}
}