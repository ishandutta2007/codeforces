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

int n, m, p;
int a[305][305];
int cdst[305][305];
vector<pi> pnts[305 * 305];

void solve1(vector<pi> &v1, vector<pi> &v2){
	for(auto &i : v2){
		for(auto &j : v1){
			cdst[i.first][i.second] = min(cdst[i.first][i.second], 
				cdst[j.first][j.second] + abs(j.second - i.second) + abs(j.first - i.first));
		}
	}
}

int d[4][305][305];

void solve2(vector<pi> &v1, vector<pi> &v2){
	memset(d, 0x3f, sizeof(d));
	for(auto &i : v1){
		for(int j=0; j<4; j++){
			d[j][i.first][i.second] = cdst[i.first][i.second];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			d[0][i][j] = min(d[0][i][j], d[0][i][j-1] + 1);
			d[0][i][j] = min(d[0][i][j], d[0][i-1][j] + 1);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=m; j; j--){
			d[1][i][j] = min(d[1][i][j], d[1][i][j+1] + 1);
			d[1][i][j] = min(d[1][i][j], d[1][i-1][j] + 1);
		}
	}
	for(int i=n; i; i--){
		for(int j=1; j<=m; j++){
			d[2][i][j] = min(d[2][i][j], d[2][i][j-1] + 1);
			d[2][i][j] = min(d[2][i][j], d[2][i+1][j] + 1);
		}
	}
	for(int i=n; i; i--){
		for(int j=m; j; j--){
			d[3][i][j] = min(d[3][i][j], d[3][i][j+1] + 1);
			d[3][i][j] = min(d[3][i][j], d[3][i+1][j] + 1);
		}
	}
	for(auto &i : v2){
		for(int k=0; k<4; k++){
			cdst[i.first][i.second] = min(cdst[i.first][i.second], d[k][i.first][i.second]);
		}
	}
}

int main(){
	cin >> n >> m >> p;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
			pnts[a[i][j]].push_back({i, j});
		}
	}
	memset(cdst, 0x3f, sizeof(cdst));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j] == 1){
				cdst[i][j] = abs(i - 1) + abs(j - 1);			
			}
		}
	}
	for(int i=2; i<=p; i++){
		if(pnts[i-1].size() <= 300) solve1(pnts[i-1], pnts[i]);
		else{
			solve2(pnts[i-1], pnts[i]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j] == p){
				cout << cdst[i][j];
			}
		}
	}

}