#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=1<<10;
const ll inf=1LL<<50;
const double eps=1e-9;

struct point {
	int x,y;
	point() {}
	point (int x, int y) : x(x), y(y) {}
	point operator-(const point &b) {
		return point(x-b.x,y-b.y);
	}
	int f() {
		return sqr(x)+sqr(y);
	}
};

struct edge {
	int w,a,b;
	edge () {}
	edge (int w, int a, int b) : w(w), a(a), b(b) {}
	bool operator< (const edge &e) {
		return w>e.w || w==e.w && a<e.a || w==e.w && a==e.a && b<e.b;
	}
};

int n,k;
bool vis[maxn];
int order[maxn];
point a[maxn];
vector<int> b[maxn];
vector<edge> v;
//bool vct[maxn];

bool cmp(int i, int j) {
	return b[i].size()>b[j].size() || b[i].size()==b[j].size() && i<j;
}

bool check(int x) {
	bool res=false, f=true;
	res|=vis[x];
	for (int i=0; i<b[x].size(); i++)
		f&=vis[b[x][i]];
	res|=f;
	return res;
}

bool rec(int x, int l, bool print) {
	while (l<n && check(order[l])) l++;
	int cur=order[l];
	if (l==n) {
		if (!print) return true;
		for (int i=0; i<n; i++) if (vis[i]) cout << i+1 << ' ';
		exit(0);
	}
	bool ff=false;
	int cnt=0;
	for (int i=0; i<b[cur].size(); i++) cnt+=!vis[b[cur][i]];

	vis[cur]=true;
	if (cnt>1 && x+1<=k) ff=rec(x+1,l+1,print);
	vis[cur]=false;
	if (ff) return true;

	vector<char> vct(b[cur].size());
	for (int i=0; i<b[cur].size(); i++) {
		vct[i]=(vis[b[cur][i]]);
		vis[b[cur][i]]=true;
	}
	ff=false;
	if (x+cnt<=k)  ff=rec(x+cnt,l+1,print); 
	for (int i=0; i<b[cur].size(); i++)
		vis[b[cur][i]]=vct[i];
	return ff;
}

bool f(int x, bool print) {
	for (int i=0; i<n; i++) {
		b[i].clear();
		order[i]=i;
		vis[i]=false;
	}
	for (int i=0; i<x; i++) {
		b[v[i].a].push_back(v[i].b);
		b[v[i].b].push_back(v[i].a);
	}
	sort(order,order+n,cmp);
	return rec(0,0,print);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			v.push_back(edge((a[i]-a[j]).f(),i,j));
		}
	}
	sort(v.begin(),v.end());
	int l=1, r=v.size();
	while (r-l>1) {
		int m=(l+r)>>1;
		if (f(m,0)) l=m;
		else r=m;
	}
	f(r,1);
	f(l,1);
	return 0;
}