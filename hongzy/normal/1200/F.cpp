#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1000 + 10;
const int mo = 2520;

int q, n, k[N], m[N], e[N][10], f[N][mo + 5], d[N][mo + 5], node[N * mo];
bool vis[N][mo + 5], bo[N];

int solve(int u, int c) {
	vis[u][c] = 1;
	if(f[u][c]) return f[u][c];
	node[d[u][c]] = u;
	int v = e[u][c % m[u]], cv = (c + k[v]) % mo;
	if(vis[v][cv]) {
		if(f[v][cv]) return f[u][c] = f[v][cv];
		int dl = d[v][cv], dr = d[u][c];
		for(int i = dl; i <= dr; i ++) bo[node[i]] = 0;
		for(int i = dl; i <= dr; i ++) if(!bo[node[i]]) {
			bo[node[i]] = 1; f[u][c] ++;
		}
		return f[u][c];
	}
	d[v][cv] = d[u][c] + 1;
	return f[u][c] = solve(v, cv);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", k + i), k[i] = (k[i] % mo + mo) % mo;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", m + i);
		for(int j = 0; j < m[i]; j ++) scanf("%d", &e[i][j]);
	}
	scanf("%d", &q);
	while(q --) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, ((y + k[x]) % mo + mo) % mo));
	}
	return 0;
}