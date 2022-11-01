#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int> pii;

const int N = 3010; 
vector < int > p[N]; 
vector < pii > tf[N]; 
int n, u, sz[N][N], dis[N][N]; 
ll f[N][N]; 
void dfs(int x, int fa) { 
	sz[u][x] = 1; 
	for (int y : p[x]) if (y != fa) { 
		dis[u][y] = dis[u][x] + 1; 
		dfs(y, x); 
		sz[u][x] += sz[u][y]; 
	} 
} 
int main() { 
	scanf("%d", & n); 
	for (int i = 1; i <= n - 1; i ++) { 
		int x, y; 
		scanf("%d%d", & x, & y); 
		p[x].pb(y); 
		p[y].pb(x); 
	} 
	for (int i = 1; i <= n; i ++) dfs(u = i, 0); 
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (i != j) tf[dis[i][j]].pb(mp(i, j)); 
	ll ans = 0; 
	int ax, ay; 
	for (int i = n; i; i --) { 
		for (pii t : tf[i]) { 
			int x = t.xx, y = t.yy; 
			ll nf = 0; 
			for (int z : p[x]) if (dis[y][z] == dis[y][x] + 1) { 
				ll tf = f[y][z]; 
				if (tf > nf) nf = tf; 
			} 
			for (int z : p[y]) if (dis[x][z] == dis[x][y] + 1) { 
				ll tf = f[x][z]; 
				if (tf > nf) nf = tf; 
			} 
			f[x][y] = nf + sz[y][x] * sz[x][y]; 
			if (f[x][y] > ans) ans = f[x][y], ax = x, ay = y; 
		} 
	} 
	printf("%lld\n", ans); 
}