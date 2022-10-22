#include<bits/stdc++.h>
using namespace std;
const int mn = 1e5 + 10;
vector<int> g[mn], nu[mn];
int d[mn],o[mn],anc[mn][17];
bool comp(const int&a, const int&b) { return o[a] < o[b]; }
int cur;
void dfs(int x) {
	o[x] = ++cur;
	nu[d[x]].push_back(x);
	for (int y : g[x]) {
		d[y] = d[x] + 1;
		dfs(y);
	}
}
int climb(int a, int b) {
	for (int i = 0; i < 17; i++)if ((b >> i) & 1)a = anc[a][i];
	return a;
}
int main() {
	int n,q,a,b,i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &anc[i][0]), g[anc[i][0]].push_back(i);
	for (i = 1; i <= n; i++)if (anc[i][0] == 0)dfs(i);
	for (i = 1; i < 17; i++)for (j = 1; j <= n; j++)anc[j][i] = anc[anc[j][i - 1]][i - 1];
	for (i = 1; i <= n; i++)sort(nu[i].begin(), nu[i].end(), comp);
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &a, &b);
		int p = climb(a, b);
		if (p == 0) { printf("0 "); continue; }
		int cur = -1,lo;
		for (i = 1 << 16; i; i >>= 1) {
			if (cur + i >= nu[d[a]].size())continue;
			int cand = nu[d[a]][cur + i];
			if (o[cand] <o[a] &&climb(cand, b) != p)cur += i;
		}
		lo = cur;
		cur = -1;
		for (i = 1 << 16; i; i >>= 1) {
			if (cur + i >= nu[d[a]].size())continue;
			int cand = nu[d[a]][cur + i];
			if (o[cand] <= o[a] || climb(cand, b) == p)cur += i;
		}
		printf("%d ", cur - lo - 1);
	}
}