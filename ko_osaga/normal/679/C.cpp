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
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int n, k;
char str[505][505];
int psum[505][505], area[505][505], area2[250005];
int idx[505][505];

vector<pi> dfn;

int dfs(int x, int y, int z){
	if(idx[x][y]) return 0;
	idx[x][y] = z;
	dfn.emplace_back(x, y);
	int ret = 1;
	for(int i=0; i<4; i++){
		if(x + dx[i] <= 0 || x + dx[i] > n || y + dy[i] <=0 || y + dy[i] > n){
			continue;
		}
		if(str[x+dx[i]][y+dy[i]] == '.'){
			ret += dfs(x + dx[i], y + dy[i], z);
		}
	}
	return ret;
}

int piv;
int diffarr[505][505];

int getsum(int sx, int ex, int sy, int ey){
	return psum[ex][ey] - psum[sx-1][ey] - psum[ex][sy-1] + psum[sx-1][sy-1];
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> (str[i] + 1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			psum[i][j] = (str[i][j] == '.') + psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];
			if(!idx[i][j] && str[i][j] == '.'){
				piv++;
				int p = dfs(i, j, piv);
				area2[piv] = p;
				int lx = 1e9, ly = 1e9, hx = -1e9, hy = -1e9;
				for(auto &i : dfn){
					lx = min(lx, i.first);
					ly = min(ly, i.second);
					hx = max(hx, i.first);
					hy = max(hy, i.second);
					area[i.first][i.second] = p;
				}
				if(hx - lx + 1 <= k && hy - ly + 1 <= k){
					int sx = max(hx - k + 1, 1);
					int ex = lx;
					int sy = max(hy - k + 1, 1);
					int ey = ly;
					diffarr[sx][sy]+=p;
					diffarr[ex+1][sy] -= p;
					diffarr[sx][ey+1] -= p;
					diffarr[ex+1][ey+1] += p;
				}
				dfn.clear();
			}
		}
	}
	for(int i=1; i<=n-k+1; i++){
		for(int j=1; j<=n-k+1; j++){
			diffarr[i][j] += diffarr[i][j-1];
		}
	}
	for(int i=1; i<=n-k+1; i++){
		for(int j=1; j<=n-k+1; j++){
			diffarr[i][j] += diffarr[i-1][j];
		}
	}
	int ret = 0;
	bool vis[250005] = {};
	for(int i=1; i<=n-k+1; i++){
		for(int j=1; j<=n-k+1; j++){
			int redeem = k * k - getsum(i, i+k-1, j, j+k-1);
			vector<int> p;
			for(int l=j; l<=j+k-1; l++){
				if(idx[i-1][l]){
					p.push_back(idx[i-1][l]);
				}
				if(idx[i+k][l]){
					p.push_back(idx[i+k][l]);
				}
			}
			for(int l=i; l<=i+k-1; l++){
				if(idx[l][j-1]){
					p.push_back(idx[l][j-1]);
				}
				if(idx[l][j+k]){
					p.push_back(idx[l][j+k]);
				}
			}
			for(auto &i : p){
				if(vis[i]) continue;
				redeem += area2[i];
				vis[i]= 1;
			}
			for(auto &i : p){
				vis[i] = 0;
			}
			ret = max(ret, redeem + diffarr[i][j]);
		}
	}
	cout << ret;
}