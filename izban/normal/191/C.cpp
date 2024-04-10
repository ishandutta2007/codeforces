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

string str(int i) {
	stringstream ss;
	ss << i;
	string res="";
	ss >> res;
	return res;
}

const int maxn=1<<17, inf=1000000000;
const ll q=1000000007;
const double eps=1e-9;


int n,k,cnt;
int g[maxn],x[maxn],y[maxn],ans[maxn],l[maxn],r[maxn];
pair<int,int> b[4*maxn];
vector<int> e[maxn];
map<pair<int,int>,int> mp;

void dfs1(int v, int p=-1, int x=0) {
	l[v]=r[v]=cnt;
	b[cnt++]=make_pair(x,v);
	for (int i=0; i<e[v].size(); i++) {
		int u=e[v][i];
		if (u==p) continue;
		dfs1(u,v,x+1);
		r[v]=cnt;
		b[cnt++]=make_pair(x,v);
	}
}

pair<int,int> t[16*maxn];

void build(int v, int tl, int tr) {
	if (tl==tr) {
		t[v]=b[tl];
		return;
	}
	int tm=(tl+tr)>>1;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=min(t[v*2],t[v*2+1]);
}

pair<int,int> lca(int v, int tl, int tr, int l, int r) {
	if (l>r) return make_pair(inf,inf);
	if (tl==l && tr==r)
		return t[v];
	int tm=(tl+tr)>>1;
	return min(lca(v*2,tl,tm,l,min(r,tm)),lca(v*2+1,tm+1,tr,max(l,tm+1),r));
}

int dfs2(int v, int p=-1) {
	int cur=g[v];
	for (int i=0; i<e[v].size(); i++) {
		int u=e[v][i];
		if (u==p) continue;
		int o=dfs2(u,v);
		ans[mp[make_pair(u,v)]]=o;
		cur+=o;
	}
	return cur;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n-1; i++) {
		cin >> x[i] >> y[i];
		e[x[i]].push_back(y[i]);
		e[y[i]].push_back(x[i]);
		mp[make_pair(x[i],y[i])]=mp[make_pair(y[i],x[i])]=i;
	}
	dfs1(1);
	build(1,0,cnt-1);
	cin >> k;
	for (int i=0; i<k; i++) {
		int x,y;
		cin >> x >> y;
		int z=lca(1,0,cnt-1,min(l[x],l[y]),max(r[x],r[y])).second;
		g[x]+=1;
		g[y]+=1;
		g[z]-=2;
	}
	dfs2(1);
	for (int i=0; i<n-1; i++)
		cout << ans[i] << ' ';
	return 0;
}