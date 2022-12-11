#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 400 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
char res[N];
bool vis[N], G[N][N];
int len;
void dfs(int u) {
	res[++ len] = u + 'a'; vis[u] = 1;
	for(int i = 0; i < 26; i ++)
		if(G[u][i] && !vis[i]) dfs(i);
}
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		static char s[N];
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		for(int i = 0; i < 26; i ++)
			fill(G[i], G[i] + 26, 0);
		for(int i = 2; i <= n; i ++) {
			int u = s[i - 1] - 'a';
			int v = s[i] - 'a';
			G[u][v] = G[v][u] = 1;
		}
		bool tag = 1;
		vector<int> d1; d1.clear();
		for(int i = 0; i < 26; i ++) {
			int d = 0;
			for(int j = 0; j < 26; j ++)
				if(G[i][j]) d ++;
			if(d > 2) {
				tag = 0; break ; 
			}
			if(d != 2) d1.push_back(i);
		}
		if(tag == 0) {
			puts("NO"); continue ;
		}
		fill(vis, vis + 26, 0); len = 0;
		for(int i = 0; i < (int) d1.size(); i ++) {
			int u = d1[i];
			if(!vis[u]) dfs(u);
		}
		if(len != 26) {
			puts("NO"); continue ;
		}
		puts("YES");
		res[len + 1] = 0;
		puts(res + 1);
	}
	return 0;
}