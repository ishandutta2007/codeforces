#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100005;

int n;

struct Edge {
	int u, v, id, num;
	double len;
	Edge(){}
	Edge(int u, int v, int id) {
		this->u = u;
		this->v = v;
		this->id = id;
 	}
} e[N];

vector<Edge> g[N];

int dfs(int u, int p) {
	int sz = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		if (v == p) continue;
		int tmp = dfs(v, u);
		sz += tmp;
		e[g[u][i].id].num = tmp;
 	}
 	return sz;
}

int main() {
	scanf("%d", &n);
	int u, v;
 	double  w;
 	for (int i = 1; i <= n - 1; i++) {
	 	scanf("%d%d%lf", &u, &v, &w);
	 	e[i].len = w;
	 	g[u].push_back(Edge(u, v, i));
	 	g[v].push_back(Edge(v, u, i));
 	}
 	dfs(1, 0);
 	int q;
 	scanf("%d", &q);
 	int id, vv;
 	double sum = 0;
  	for (int i = 1; i <= n - 1; i++) {
 	  	sum += (double)(n - 2) * (e[i].num) * (n - e[i].num) * (e[i].len);
  	}
  	double c1 = (double)n * (n - 1) * (n - 2) / 2 / 3;
 	while (q--) {
		scanf("%d%d", &id, &vv);
		sum -= (double)(n - 2) * (e[id].num) * (n - e[id].num) * (e[id].len - vv);
		e[id].len = vv;
		printf("%.10lf\n", sum / c1);
	}
	return 0;
}