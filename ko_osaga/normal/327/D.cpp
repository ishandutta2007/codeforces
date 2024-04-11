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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

vector<pi> vis;
char str[505][505];
int n, m;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
	if(str[x][y] == '#') return;
	str[x][y] = '#';
	vis.push_back(pi(x, y));
	for(int i=0; i<4; i++){
		if(x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= n || y + dy[i] >= m){
			continue;
		}
		dfs(x + dx[i], y + dy[i]);
	}
}

struct oper{
	char t;
	int x, y;
};

vector<oper> ret;

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> str[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] != '#'){
				dfs(i, j);
				for(auto &i : vis){
					ret.push_back({'B', i.first, i.second});
				}
				while(vis.size() > 1){
					pi i = vis.back();
					ret.push_back({'D', i.first, i.second});
					ret.push_back({'R', i.first, i.second});
					vis.pop_back();
				}
				vis.pop_back();
			}
		}
	}
	printf("%d\n",ret.size());
	for(auto &i : ret){
		printf("%c %d %d\n",i.t, i.x+1, i.y+1);
	}
}