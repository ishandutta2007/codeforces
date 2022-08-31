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

int n, m, k;
int dp[31][31][51];

int f(int x, int y, int z){
	if(z == 0) return 0;
	if(z > x * y) return 1e9;
	if(z == x * y) return 0;
	if(~dp[x][y][z]) return dp[x][y][z];
	int ret = 1e9;
	for(int i=1; i<x; i++){
		for(int j=0; j<=z-j; j++){
			ret = min(ret, f(i, y, j) + f(x-i, y, z-j) + y * y);
		}
	}
	for(int i=1; i<y; i++){
		for(int j=0; j<=z-j; j++){
			ret = min(ret, f(x, i, j) + f(x, y-i, z-j) + x * x);
		}
	}
	return dp[x][y][z] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int t;
	cin >> t;
	while(t--){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		printf("%d\n",f(x, y, z));
	}
}