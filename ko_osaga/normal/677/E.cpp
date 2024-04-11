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

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
char str[1005][1005];
int dp[8][1005][1005];
bool vis[8][1005][1005];
pi prec[8][1005][1005];

int get(int x, int y, int d){
	if(min(x, y) <= 0 || max(x, y) > n) return 0;
	if(~dp[d][x][y]) return dp[d][x][y];
	if(str[x][y] == '0') return dp[d][x][y] = 0;
	return dp[d][x][y] = get(x+dx[d], y+dy[d], d) + 1;
}

pi get2(int x, int y, int d){
	if(min(x, y) <= 0 || max(x, y) > n) return pi(0, 0);
	if(vis[d][x][y]) return prec[d][x][y];
	vis[d][x][y] = 1;
	pi t = get2(x + dx[d], y + dy[d], d);
	if(str[x][y] == '2') t.first++;
	if(str[x][y] == '3') t.second++;
	return prec[d][x][y] = t;
}

int solve(vector<pi> cnd){
	double lgmax = -1;
	int pos = -1;
	for(int i=0; i<cnd.size(); i++){
		double tmp = log(2) * cnd[i].first + log(3) * cnd[i].second;
		if(tmp > lgmax){
			lgmax =tmp;
			pos = i;
		}
	}
	lint ret= 1, mod = 1e9 + 7;
	for(int i=0; i<cnd[pos].first; i++){
		ret *= 2;
		ret %= mod;
	}
	for(int i=0; i<cnd[pos].second; i++){
		ret *= 3;
		ret %= mod;
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> (str[i] + 1);
	}
	memset(dp, -1, sizeof(dp));
	vector<pi> cnd;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(str[i][j] == '0'){
				continue;
			}
			int dist1 = 1e9, dist2 = 1e9;
			for(int k=0; k<8; k++){
				if(k % 2 == 0){
					dist1 = min(dist1, get(i, j, k));
				}
				else{
					dist2 = min(dist2, get(i, j, k));
				}
			}
			pi t1(0, 0), t2(0, 0);
			if(str[i][j] == '2') t1.first++, t2.first++;
			else if(str[i][j] == '3') t1.second++, t2.second++;
			for(int k=0; k<8; k++){
				if(k % 2 == 0){
					pi p1 = get2(i + dx[k], j + dy[k], k);
					pi p2 = get2(i + dist1 * dx[k], j + dist1 * dy[k], k);
					p1.first -= p2.first;
					p1.second -= p2.second;
					t1.first += p1.first;
					t1.second += p1.second;
				}
				if(k % 2 == 1){
					pi p1 = get2(i + dx[k], j + dy[k], k);
					pi p2 = get2(i + dist2 * dx[k], j + dist2 * dy[k], k);
					p1.first -= p2.first;
					p1.second -= p2.second;
					t2.first += p1.first;
					t2.second += p1.second;
				}
			}
			cnd.push_back(t1);
			cnd.push_back(t2);
		}
	}
	if(cnd.empty()){
		puts("0");
	}
	else{
		printf("%d",solve(cnd));
	}
}