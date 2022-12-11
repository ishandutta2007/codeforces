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

const int N = 1e5 + 10;
const int mod = 1e9 + 7;	

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
vector<int> G[N];
bool mat[N], use[N];
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int n; scanf("%d", &n);
		fill(use + 1, use + n + 1, 0);
		for(int i = 1; i <= n; i ++) {
			int x, y; scanf("%d", &x); G[i].clear();
			mat[i] = 0;
			for(int j = 1; j <= x; j ++) {
				scanf("%d", &y); G[i].push_back(y);
			}
			sort(G[i].begin(), G[i].end());
			for(int j = 0; j < x; j ++) {
				int v = G[i][j];
				if(!use[v] && !mat[i]) {
					mat[i] = 1; use[v] = 1; break ;
				}
			} 
		}
		int x = -1, y = -1;
		for(int i = 1; i <= n; i ++) if(!mat[i]) x = i;
		for(int i = 1; i <= n; i ++) if(!use[i]) y = i;
		if(x == -1) puts("OPTIMAL");
		else {
			puts("IMPROVE");
			printf("%d %d\n", x, y); 
		}
	} 
	return 0;
}