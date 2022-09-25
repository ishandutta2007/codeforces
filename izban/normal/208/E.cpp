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
#pragma comment(linker,"/STACK:128000000")

const int maxn=1<<17;

int n,m,time;
int l[maxn],r[maxn],h[maxn];
vector<int> e[maxn];
vector<pair<int,int> > a[maxn];

void dfs(int v, int x) {
	h[v]=x;
	l[v]=time++;
	for (int i=0; i<e[v].size(); i++)
		dfs(e[v][i],x+1);
	r[v]=time++;
	a[x].push_back(make_pair(r[v],v));
}

int f(int l, int r, int x){ 
	vector<pair<int,int>>::iterator L,R;
	L=lower_bound(a[x].begin(),a[x].end(),make_pair(l,0));
	R=upper_bound(a[x].begin(),a[x].end(),make_pair(r,n+1));	
	return R-L;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}
	dfs(0,0);
	for (int i=0; i<maxn; i++) 
		sort(a[i].begin(),a[i].end());

	cin >> m;
	for (int i=0; i<m; i++) {
		int x,y;
		cin >> x >> y;
		if (h[x]-y<=0) {
			cout << "0 ";
			continue;
		}
		vector<pair<int,int> >::iterator it1=lower_bound(a[h[x]-y].begin(),a[h[x]-y].end(),make_pair(l[x],x));
		vector<pair<int,int> >::iterator it2=lower_bound(a[h[x]-y+1].begin(),a[h[x]-y+1].end(),make_pair(l[x],x));
		//it1--; if (y!=1) it2--;
		int v=it1->second, v1=it2->second;
		int ans=f(l[v],r[v],h[x]);
		ans-=1;
		cout << ans << ' ';
	}
	return 0;
}