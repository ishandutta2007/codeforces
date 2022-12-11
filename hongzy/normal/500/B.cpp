#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;

const int N = 303;

int n, a[N], pos[N];
bitset<N> g[N], vis;
char s[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1); g[i].reset();
		for(int j = 1; j <= n; j ++) {
			g[i][j] = s[i][j] - '0';
		}
	}
	
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			if(g[i][k]) g[i] |= g[k];
	for(int i = 1; i <= n; i ++) g[i][i] = 1;
	vis.reset();
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) if(!vis[j] && g[i][pos[j]]) {
			vis[j] = 1; printf("%d ", j); break ;
		}
	}
	return 0;
}