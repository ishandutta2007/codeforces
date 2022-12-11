#include <algorithm>
#include <cstdio>
#include <vector>

inline void up(int & x, int y) {if(x < y) x = y;}

typedef std :: pair<int, int> P;
typedef std :: pair<int, P > E;

std :: vector<E> edges;
int n, m, f[300010], d[300010];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v, w; i <= m; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		edges.push_back(E(w, P(u, v)));
	}
	std :: sort(edges.begin(), edges.end());
	for(int i = 0, j; i < m; i ++) {
		for(j = i + 1; j < m; j ++) 
			if(edges[i].first != edges[j].first) break;
		j --;
		for(int k = i; k <= j; k ++)
			up(d[edges[k].second.second], f[edges[k].second.first] + 1);
		for(int k = i; k <= j; k ++)
			up(f[edges[k].second.second], d[edges[k].second.second]);
		i = j;
	}
	int ans = f[1];
	for(int i = 2; i <= n; i += 1)
		if(ans < f[i]) ans = f[i];
	printf("%d\n", ans);
	return 0;
}