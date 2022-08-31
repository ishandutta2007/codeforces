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
typedef pair<int,int> pi;

vector<pi> graph[50005];

int n, k;
bool vis[50005];

int size[50005], msize[50005];
vector<int> dfn;

int dfs(int x, int p){
	size[x] = 1;
	msize[x] = 1;
	dfn.push_back(x);
	for(int i=0; i<graph[x].size(); i++){
		int pos = graph[x][i].second;
		if(pos == p) continue;
		if(vis[pos]) continue;
		int t = dfs(pos, x);
		size[x] += t;
		msize[x] = max(msize[x], t);
	}
	return size[x];
}

int get_center(int x){
	dfn.clear();
	dfs(x, 0);
	int retp = 1e9, retv = -1;
	for(int i=0; i<dfn.size(); i++){
		int p = max(msize[dfn[i]], (int)dfn.size() - size[dfn[i]]);
		if(retp > p){
			retp = p;
			retv = dfn[i];
		}
	}
	return retv;
}

int dep[50005];
vector<int> bfs(int x){
	vector<int> ret;
	queue<int> q, pq;
	q.push(x);
	pq.push(-1);
	dep[x] = 0;
	while(!q.empty()){
		x = q.front();
		int par = pq.front();
		q.pop();
		pq.pop();
		ret.push_back(dep[x]);
		for(int j=0; j<graph[x].size(); j++){
			int p = graph[x][j].second;
			if(p == par) continue;
			if(vis[p]) continue;
			dep[p] = graph[x][j].first + dep[x];
			q.push(p);
			pq.push(x);
		}
	}
	return ret;
}

lint solve(vector<int> &v){
	sort(v.begin(), v.end());
	lint ret = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i] + v[i] == k) ret--;
		ret += upper_bound(v.begin(), v.end(), k - v[i]) - 
		lower_bound(v.begin(), v.end(), k - v[i]);
	}
	return ret / 2;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(pi(1, e));
		graph[e].push_back(pi(1, s));
	}
	queue<int> q;
	q.push(1);
	lint ret = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		x = get_center(x);
		vis[x] = 1;
		vector<int> all;
		for(int i=0; i<graph[x].size(); i++){
			if(!vis[graph[x][i].second]){
				q.push(graph[x][i].second);
				vector<int> tmp = bfs(graph[x][i].second);
				for(int j=0; j<tmp.size(); j++){
					tmp[j] += graph[x][i].first;
					all.push_back(tmp[j]);
					if(tmp[j] == k) ret++;
				}
				ret -= solve(tmp);
			}
		}
		ret += solve(all);
	}
	cout << ret;
}