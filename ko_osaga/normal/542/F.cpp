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
typedef pair<int, int> pi;

vector<int> elem[105];
int n, t;
int dp[1005][105];

int f(int x, int y){
	if(y == 0) return 0;
	if(~dp[x][y]) return dp[x][y];
	int ret = f(min(2*x, n), y-1);
	for(int i=1; i<=x && i <= elem[y].size(); i++){
		ret = max(ret, f(min(2*(x-i), n), y-1) + elem[y][i-1]);
	}
	return dp[x][y] = ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> t;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		elem[x].push_back(y);
	}
	for(int i=1; i<=t; i++){
		sort(elem[i].begin(), elem[i].end());
		reverse(elem[i].begin(), elem[i].end());
		int sum = 0;
		for(auto &j : elem[i]){
			sum += j;
			j = sum;
		}
	}
	cout << f(1, t);
}