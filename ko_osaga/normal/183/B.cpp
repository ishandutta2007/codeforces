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

int n, m, ret[1000005];
int dp[255][255];
pi a[255];

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = c.first - a.first;
	int dx2 = b.second - a.second;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int f(int x, int y){
	if(~dp[x][y]) return dp[x][y];
	for(int j=y+1; j<m; j++){
		if(ccw(a[x], a[y], a[j]) == 0){
			return dp[x][y] = f(y, j) + 1;
		}
	}
	return dp[x][y] = 2;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a+m);
	for(int i=0; i<m; i++){
		for(int j=i+1; j<m; j++){
			if(a[i].first == a[j].first) continue;
			int s = 1, e = n;
			while(s != e){
				int m = (s+e)/2;
				if(abs(ccw(pi(0, m), a[i], a[j])) <= abs(ccw(pi(0, m+1), a[i], a[j]))){
					e = m;
				}
				else s = m+1;
			}
			if(ccw(pi(0, s), a[i], a[j]) == 0){
				ret[s] = max(ret[s], f(i, j));
			}
		}
	}
	int res = 0;
	for(int i=1; i<=n; i++){
		res += max(ret[i], 1);
	}
	cout << res;
}