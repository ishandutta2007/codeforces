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

struct pnt{
	int x, y, v;
}a[1000005];

vector<vector<int> > ret;
vector<vector<bool> > vis;

int n, m;
int xcur[1000005], ycur[1000005];

vector<pi> candx, candy;
vector<pi> processed;

int dfs1(pi x){
	if(vis[x.first][x.second]) return 0;
	vis[x.first][x.second] = 1;
	processed.push_back(x);
	auto v = lower_bound(candx.begin(), candx.end(), x);
	auto u = lower_bound(candy.begin(), candy.end(), x, [&](const pi &a, const pi &b){
			return pi(a.second, a.first) < pi(b.second, b.first);
	});
	int ret = max(xcur[x.first], ycur[x.second]) + 1;
	if(u != candy.end()-1 && (u+1)->second == x.second){
		ret = max(ret, dfs1(*(u+1)));
	}
	if(u != candy.begin() && (u-1)->second == x.second){
		ret = max(ret, dfs1(*(u-1)));
	}
	if(v != candx.end()-1 && (v+1)->first == x.first){
		ret = max(ret, dfs1(*(v+1)));
	}
	if(v != candx.begin() && (v-1)->first == x.first){
		ret = max(ret, dfs1(*(v-1)));
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	ret.resize(n);
	vis.resize(n);
	for(int i=0; i<n; i++){
		ret[i].resize(m);
		vis[i].resize(m);
		for(int j=0; j<m; j++){
			scanf("%d",&a[i*m+j].v);
			a[i*m+j].x = i, a[i*m+j].y = j;
		}
	}
	sort(a, a+n*m, [&](const pnt &a, const pnt &b){
		return a.v < b.v;
	});
	for(int i=0; i<n*m; ){
		int e = i;
		while(e < n*m && a[e].v == a[i].v) e++;
		candx.clear();
		candy.clear();
		for(int j=i; j<e; j++){
			candx.push_back(pi(a[j].x, a[j].y));
			candy.push_back(pi(a[j].x, a[j].y));
		}
		sort(candx.begin(), candx.end());
		sort(candy.begin(), candy.end(), [&](const pi &a, const pi &b){
			return pi(a.second, a.first) < pi(b.second, b.first);
		});
		for(int j=i; j<e; j++){
			if(vis[a[j].x][a[j].y]) continue;
			int tmp = dfs1(pi(a[j].x, a[j].y));
			for(auto &i : processed){
				ret[i.first][i.second] = tmp;
				xcur[i.first] = max(xcur[i.first], tmp);
				ycur[i.second] = max(ycur[i.second], tmp);
			}
			processed.clear();
		}
		i = e;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ",ret[i][j]);
		}
		puts("");
	}
}