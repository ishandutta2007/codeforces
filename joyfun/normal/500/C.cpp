#include <cstdio>
#include <cstring>

const int N = 505;
typedef long long ll;

int n, m, w[N], vis[N][N];

int v;
ll sum = 0;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &v);
		for (int j = 1; j <= n; j++)
  			sum += w[j] * vis[v][j];
     	memset(vis[v], 0, sizeof(vis[v]));
      	for (int j = 1; j <= n; j++) {
       		if (v == j) continue;
       		vis[j][v] = 1;
       	}			
	}
	printf("%lld\n", sum);
	return 0;
}