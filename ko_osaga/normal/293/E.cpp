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

int n, l, w;
vector<pi> gph[100005];
bool vis[100005];

int dep1[100005], dep2[100005];

struct bit{
	int tree[100005];
	void add(int x, int v){
		x += 2;
		while(x <= n+3){
			tree[x] += v;
			x += x & -x;
		}
	}
	int sum(int x){
		x += 2; int ret = 0;
		if(x < 0) return 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

queue<pi> que;
vector<pi> tmp;

lint bfs(int x, int p){
	tmp.clear();
	que.push(pi(x, p));
	while(!que.empty()){
		pi t = que.front();
		int pos = t.first;
		que.pop();
		tmp.emplace_back(dep1[pos], dep2[pos]);
		for(auto &i : gph[pos]){
			if(i.second == t.second) continue;
			if(vis[i.second]) continue;
			dep1[i.second] = dep1[pos] + 1;
			dep2[i.second] = dep2[pos] + i.first;
			que.push(pi(i.second, pos));
		}
	}
	sort(tmp.begin(), tmp.end(), [&](const pi &a, const pi &b){
		return a.second < b.second;
	});
	int pnt = 0;
	lint ret = 0;
	for(int i=tmp.size()-1; i>=0; i--){
		while(pnt < tmp.size() && tmp[i].second + tmp[pnt].second <= w){
			bit.add(tmp[pnt++].first, 1);
		}
		ret += bit.sum(l - tmp[i].first);
	}
	while(pnt > 0){
		bit.add(tmp[--pnt].first, -1);
	}
	for(int i=0; i<tmp.size(); i++){
		if(tmp[i].first <= l/2 && tmp[i].second <= w/2) ret--;
	}
	return ret / 2; 
}

lint solve(int x){
	lint ret = 0;
	dep1[x] = dep2[x] = 0;
	ret += bfs(x, -1);
	for(auto &i : gph[x]){
		if(!vis[i.second]){
			dep1[i.second] = 1;
			dep2[i.second] = i.first;
			ret -= bfs(i.second, x);
		}
	}
	return ret;
}

queue<int> q;
vector<int> dfn;
int sz[100005], msz[100005];

int dfs(int x, int p){
	if(vis[x]) return 0;
	sz[x] = 1;
	msz[x] = 0;
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		int t = dfs(i.second, x);
		sz[x] += t;
		msz[x] = max(msz[x], t);
	}
	dfn.push_back(x);
	return sz[x];
}

int getmid(int x){
	dfn.clear();
	int f = dfs(x, -1);
	int ret = 1e9, retp = -1;
	for(auto &i : dfn){
		int u = max(f - sz[i], msz[i]);
		if(ret > u){
			ret = u;
			retp = i;
		}
	}
	return retp;
}

int main(){
	cin >> n >> l >> w;
	for(int i=2; i<=n; i++){
		int p, w;
		scanf("%d %d",&p,&w);
		gph[p].emplace_back(w, i);
		gph[i].emplace_back(w, p);
	}
	lint ret = 0;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		x = getmid(x);
		vis[x] = 1;
		ret += solve(x);
		for(auto &i : gph[x]){
			if(!vis[i.second]){
				q.push(i.second);
			}
		}
	}
	cout << ret;
}