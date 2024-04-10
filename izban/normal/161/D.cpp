#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=100100;

string s;
int n,k;
int d[maxn][510],cursum[510];
vector<int> a[maxn];
ll ans=0;
bool vis[maxn];
int parent[maxn];


void dfs(int v, int p) {
	d[v][0]++;
	vis[v]=true;
	parent[v]=p;
	for (int i=0; i<a[v].size(); i++) {
		if (!vis[a[v][i]]) dfs(a[v][i],v);
		else continue;
		for (int j=0; j<k; j++)
			d[v][j+1]+=d[a[v][i]][j];
	}
}

void dfs1(int v) {
	ll cans=0;
	for (int i=0; i<=k; i++) cursum[i]=0;
	for (int i=0; i<a[v].size(); i++) if (a[v][i]!=parent[v]) {
		for (int j=1; j<k; j++)
			cans+=(ll)d[a[v][i]][j-1]*cursum[k-j-1];
		for (int j=1; j<k; j++) 
			cursum[j-1]+=d[a[v][i]][j-1];
	}
	ans+=cans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n-1; i++) {
		int x,y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1; i<=n; i++) dfs1(i);
	for (int i=1; i<=n; i++)
		ans+=d[i][k];
	cout << ans;
	return 0;
}