#define _CRT_SECURE_NO_DEPRECATE
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

#define all(a) (a).begin(),(a).end()

typedef vector<int> vi;
vector< vi> edges, isGoodEdge;

vi v1, v2, numv;

int dfs1(int p, int from) {
	int nv = 1;
	for (int i = 0; i < (int)edges[p].size(); i++) {
		if (edges[p][i] == from) continue;
		nv += dfs1(edges[p][i], p);
		if (isGoodEdge[p][i]) {
			v1[p] += numv[edges[p][i]];
		} else {
			v1[p] += v1[edges[p][i]];
		}
	}
	return (numv[p] = nv);
}

void dfs2(int p, int from, int val) {
	v2[p] = val + v1[p];
	for (int i = 0; i < (int)edges[p].size(); i++) {
		if (edges[p][i] == from) continue;
		if (isGoodEdge[p][i]) {
			dfs2(edges[p][i], p, numv[0] - numv[edges[p][i]]);
		} else {
			dfs2(edges[p][i], p, v2[p] - v1[edges[p][i]]);
		}
	}
}

int isGoodNum(int p) {
	while (p) {
		if (p%10 != 7 && p%10 != 4) return 0;
		p /= 10;
	}
	return 1;
}

int main(void) {
	int n;
	scanf("%d", &n);
	edges.resize(n);
	isGoodEdge.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u; --v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		isGoodEdge[u].push_back(isGoodNum(w));
		isGoodEdge[v].push_back(isGoodNum(w));
	}
	v1.resize(n);
	v2.resize(n);
	numv.resize(n);
	dfs1(0, -1);
	dfs2(0, -1, 0);
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += v2[i] * (long long)(v2[i] - 1);
	}
	printf("%lld\n", res);
	return 0;
}