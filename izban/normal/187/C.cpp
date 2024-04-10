#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=1<<17, inf=1000000007;
const double eps=1e-9;

int n,m,k,s,t,ans;
bool vol[maxn],vis[maxn];
int d[maxn];
vector<int> e[maxn];

void reading() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0; i<k; i++) {
		int x;
		scanf("%d",&x);
		vol[x]=1;
	}
	for (int i=0; i<m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	scanf("%d%d",&s,&t);
	vol[t]=1;
}

void bfs() {
	queue<int> q;
	for (int i=1; i<=n; i++) {
		d[i]=vol[i]?0:inf;
		if (vol[i]) q.push(i);
	}
	while (!q.empty()) {
		int v=q.front();
		q.pop();
		for (int i=0; i<e[v].size(); i++) if (d[e[v][i]]==inf) {
			d[e[v][i]]=d[v]+1;
			q.push(e[v][i]);
		}
	}
}

bool dfs(int v, int x) {
	vis[v]=true;
	if (v==t) return true;
	bool res=false;
	for (int i=0; i<e[v].size(); i++) 
		if (!vis[e[v][i]] && d[e[v][i]]+d[v]+1<=x)
			res|=dfs(e[v][i],x);
	return res;
}

bool f(int x) {
	for (int i=1; i<=n; i++) vis[i]=false;
	return dfs(s,x);
}

void solve() {
	int l=1, r=n;
	while (r-l>1) {
		int m=(l+r)>>1;
		if (f(m)) r=m;
		else l=m;
	}
	if (f(l)) ans=l;
	else ans=r;
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	reading();
	bfs();
	solve();
	cout << (ans==n?-1:ans);

    return 0;
}