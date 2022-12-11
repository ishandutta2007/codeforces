#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 2000 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, d[N];
vector<int> G[N];
bool ban[N];
int lca(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout); int xx;
	scanf("%d", &xx);
	return xx;
}
void res(int r) {
	printf("! %d\n", r);
	fflush(stdout);
}
int main() {
	scanf("%d", &n);
	for(int x, y, i = 1; i < n; i ++) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y); d[x] ++;
		G[y].push_back(x); d[y] ++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(d[i] == 1) q.push(i);
	while(q.size() >= 2) {
		int u = q.front(); q.pop(); ban[u] = 1;
		int v = q.front(); q.pop(); ban[v] = 1;
		int x = lca(u, v);
		if(x == u || x == v) {
			res(x); return 0;
		} 
		for(int uu : G[u]) if(!ban[uu]) {
			d[uu] --;
			if(d[uu] == 1) q.push(uu);
		}
		for(int uu : G[v]) if(!ban[uu]) {
			d[uu] --;
			if(d[uu] == 1) q.push(uu);
		}
	}
	res(q.front());
	return 0;
}