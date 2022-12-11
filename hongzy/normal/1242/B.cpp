#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;
int n, m, ans, tr, d[N], cnt;
vector<int> G[N];
bool use[N], vis[N];
int main() {
	ucin();
	cin >> n >> m;
	for(int x, y, i = 1; i <= m; i ++) {
		cin >> x >> y;
		G[y].push_back(x);
		G[x].push_back(y);
	}
	int rt = 1;
	for(int i = 1; i <= n; i ++)
		if(G[i].size() < G[rt].size()) rt = i;
	for(int v : G[rt]) vis[v] = 1;
	for(int i = 1; i <= n; i ++) if(!vis[i]) use[i] = 1, tr ++;
	for(int i = 1; i <= n; i ++) if(!use[i]) {
		int c = 0;
		for(int v : G[i]) {
			if(use[v]) {
				c ++;
			}
		}
		cnt ++;
		d[i] = c == tr;
	}
	fill(vis + 1, vis + n + 1, 0);
	for(int i = 1; i <= cnt; i ++) {
		int u = 0;
		for(int j = 1; j <= n; j ++) if(!use[j] && (!u || d[u] > d[j])) u = j;
		if(!u) break ;
		ans += d[u]; use[u] = 1; 
		for(int v : G[u]) vis[v] = 1;
		for(int j = 1; j <= n; j ++) if(!use[j] && !vis[j]) d[j] = 0;
		for(int v : G[u]) vis[v] = 0;
	}
	cout << ans << endl;
	return 0;
}