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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int n, m;
char str[2005][2005];

inline bool ok(int x, int y){
	return !(x < 0 || y < 0 || x >= n || y >= m);
}

int getcnt(int x, int y){
	int cnt = 0;
	for(int i=x-1; i<=x; i++){
		for(int j=y-1; j<=y; j++){
			if(str[i][j] == '*') cnt++;
		}
	}
	return cnt;
}

queue<pi> q;
bool vis[2005][2005];

void erase(int x, int y){
	int px = -1, py = -1;
	for(int i=x-1; i<=x; i++){
		for(int j=y-1; j<=y; j++){
			if(str[i][j] == '*'){
				str[i][j] = '.';
				px = i, py = j;
			}
		}
	}
	for(int i=max(1, px); i<=min(n-1, px+1); i++){
		for(int j=max(1, py); j<=min(m-1,py+1); j++){
			if(getcnt(i, j) == 1 && !vis[i][j]){
				q.push(pi(i, j));
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		scanf("%s",str[i]);
		str[i][m] = '*';
	}
	if(n < 2 || m < 2){
		for(int i=0; i<n; i++){
			str[i][m] = 0;
			puts(str[i]);
		}
		return 0;
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(getcnt(i, j) == 1){
				vis[i][j] = 1;
				q.push(pi(i, j));
			}
		}
	}
	while(!q.empty()){
		pi t = q.front();
		q.pop();
		erase(t.first, t.second);
	}
	for(int i=0; i<n; i++){
		str[i][m] = 0;
		puts(str[i]);
	}
	return 0;
}