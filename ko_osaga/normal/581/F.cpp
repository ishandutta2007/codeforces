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

int n;
vector<int> gph[5005];

int sz[5005];
int dp[5005][2][5005];
int tmp[2][5005];

void solve(int x, int p){
	if(gph[x].size() == 1){
		sz[x] = 1;
		dp[x][0][0] = 0;
		dp[x][0][1] = 1e9;
		dp[x][1][0] = 1e9;
		dp[x][1][1] = 0;
	}
	else{
		dp[x][0][0] = 0;
		dp[x][0][1] = 0;
	}
	for(auto &i : gph[x]){
		if(i != p){
			solve(i, x);
			memset(tmp, 0x3f, sizeof(tmp));
			for(int j=0; j<=sz[i]; j++){
				for(int k=0; k<=sz[x]; k++){
					tmp[0][j+k] = min(tmp[0][j+k], dp[i][0][j] + dp[x][0][k]);
					tmp[0][j+k] = min(tmp[0][j+k], dp[i][1][j] + dp[x][0][k] + 1);
					tmp[1][j+k] = min(tmp[1][j+k], dp[i][0][j] + dp[x][1][k] + 1);
					tmp[1][j+k] = min(tmp[1][j+k], dp[i][1][j] + dp[x][1][k]);
				}
			}
			sz[x] += sz[i];
			for(int j=0; j<=sz[x]; j++){
				for(int k=0; k<2; k++){
					dp[x][k][j] = tmp[k][j];
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	if(n == 2){
		cout << 1;
		return 0;
	}
	for(int i=0; i<n-1; i++){
		int s, e;
		cin >> s >> e;
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(gph[i].size() == 1) cnt++;
	}
	for(int i=1; i<=n; i++){
		if(gph[i].size() != 1){
			solve(i, -1);
			cout << dp[i][0][cnt/2];
			break;
		}
	}
}