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
const int maxn=3000, inf=1000000;

struct edge {
	int a,b;
} e[maxn];


vector<int> t[maxn];
int n,m,gcol=1;
int g[maxn][maxn];
bool p[maxn][maxn];
bool used[maxn],ff[maxn];
int vis[maxn];
int timer, tin[maxn], fup[maxn];
int cc[maxn];



void IS_BRIDGE(int v, int i) {
	p[v][i]=p[i][v]=true;
}

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i=0; i<n; ++i) if (g[v][i]) {
		int to = i;
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				IS_BRIDGE(v,i);
		}
	}
}
 
void find_bridges() {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
}

void dfs1(int v, int col) {
	cc[v]=col;
	for (int i=0; i<n; i++) if (g[v][i]) {
		if (!cc[i]) {
			if (p[v][i]) {
				gcol++;
				dfs1(i,gcol);
			} else dfs1(i,col);
		}
	}
}

int d[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> e[i].a >> e[i].b;
		g[e[i].a-1][e[i].b-1]=1;
		g[e[i].b-1][e[i].a-1]=1;
		t[e[i].a-1].push_back(e[i].b-1);
		t[e[i].b-1].push_back(e[i].a-1);
	}
	find_bridges();
	//dfs1(1,1);

	/*for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) {
			if (i==j) d[i][j]=0;
			else if (p[i][j]) d[i][j]=1;
			else if (g[i][j]) d[i][j]=0;
			else d[i][j]=inf;
		}

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);*/

	int k;
	cin >> k;
	for (int i=0; i<k; i++) {
		for (int i=0; i<n; i++) vis[i]=inf, ff[i]=false;
		int x,y;
		cin >> x >> y;
		vis[x-1]=0;
		deque<int> q;
		q.push_back(x-1);
		while (!q.empty()) {
			int v=q.front();
			q.pop_front();
			if (ff[v]) continue;
			ff[v]=true;
			for (int i=0; i<t[v].size(); i++) {
				int to=t[v][i];
				if (vis[to]==inf) {
					if (!p[v][to]) {
						vis[to]=vis[v];
						q.push_front(to);
					} else {
						vis[to]=vis[v]+1;
						q.push_back(to);
					}
				}
				else if (!p[v][to]) {
					vis[to]=vis[v];
					q.push_front(to);
				}
			}
		}
		//cout << d[x-1][y-1] << endl;
		cout << vis[y-1] << endl;
	}
	return 0;
}