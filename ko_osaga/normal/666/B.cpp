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

vector<int> gph[3005];
int dist[3005][3005];
vector<pi> cnd[3005], rcnd[3005];

int ret, rx, ry, rz, ra;

void update(int a, int b, int c, int d){
	if(a == b || a == c || b == c || b == d || a == d || c == d) return;
	int dap = dist[a][b] + dist[b][c] + dist[c][d];
	if(dap > ret){
		ret = dap;
		tie(rx, ry, rz, ra) = make_tuple(a, b, c, d);
	}
}

void bfs(int x){
	bool vis[3005] = {};
	queue<int> Q;
	Q.push(x);
	vis[x] =1 ;
	dist[x][x] = 0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(auto &i : gph[v]){
			if(!vis[i]){
				vis[i] = 1;
				Q.push(i);
				dist[x][i] = dist[x][v] + 1;
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s, &e);
		gph[s].push_back(e);
	}
	memset(dist, 0x3f, sizeof(dist));
	for(int i=1; i<=n; i++){
		bfs(i);
	}
	for(int i=1; i<=n; i++){
		vector<pi> lis, rlis;
		for(int j=1; j<=n; j++){
			if(i == j) continue;
			if(dist[i][j] < 1e9) lis.emplace_back(dist[i][j], j);
			if(dist[j][i] < 1e9) rlis.emplace_back(dist[j][i], j);
		}
		sort(lis.begin(), lis.end());
		reverse(lis.begin(), lis.end());
		sort(rlis.begin(), rlis.end());
		reverse(rlis.begin(), rlis.end());
		for(int j=0; j<lis.size() && j<4; j++){
			cnd[i].push_back(lis[j]);
		}
		for(int j=0; j<rlis.size() && j<4; j++){
			rcnd[i].push_back(rlis[j]);
		}

	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dist[i][j] > 1e9 || i == j) continue;
			for(auto &k : rcnd[i]){
				for(auto &l : cnd[j]){
					update(k.second, i, j, l.second);
				}
			}
		}
	}
	printf("%d %d %d %d\n",rx, ry, rz, ra);
}