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

const int maxn=1<<17, mod=1000000007;
const double eps=1e-9;

int gx,gy;

struct point {
	int x,y,p;
	bool operator< (const point &pt) {
		ll res=1LL*(x-gx)*(pt.y-gy)-1LL*(pt.x-gx)*(y-gy);
		return res>0;
	}
} a[maxn];

bool cmp(point &a, point &b) {
	return a.y>b.y || a.y==b.y && a.x<b.x;
}

int n;
int sz[maxn],ans[maxn],p[maxn];
vector<int> e[maxn];

int dfs(int v, int pr) {
	p[v]=pr;
	for (int i=0; i<e[v].size(); i++) if (e[v][i]!=pr) {
		sz[v]+=dfs(e[v][i],v);
	}
	return ++sz[v];
}

void rec(int v, vector<point> points) {
	point x=points[0];
	ans[x.p]=v;
	points.erase(points.begin());
	gx=x.x; gy=x.y;
	sort(points.begin(),points.end());

	vector<point> b;
	int cur=0;
	for (int i=0; i<e[v].size(); i++) if (e[v][i]!=p[v]) {
		b.clear();
		for (int j=0; j<sz[e[v][i]]; j++, cur++) {
			b.push_back(points[cur]);
		}
		rec(e[v][i],b);
	}
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	scanf("%d",&n);
	for (int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].p=i;
	}
	
	dfs(1,0);
	
	vector<point> v;
	for (int i=0; i<n; i++) v.push_back(a[i]);
	sort(v.begin(),v.end(),cmp);

	rec(1,v);
	
	for (int i=0; i<n; i++) 
		cout << ans[i] << endl;
    return 0;
}