#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;
 
int n, m;
boolean *lab1, *lab2;
vector<int> *g, *rg;
 
inline void init() {
	scanf("%d%d", &n, &m);
	lab1 = new boolean[(n + 1)];
	lab2 = new boolean[(n + 1)];
	g = new vector<int>[(n + 1)];
	rg = new vector<int>[(n + 1)];
	memset(lab1, false, sizeof(boolean) * (n + 1));
	memset(lab2, false, sizeof(boolean) * (n + 1));
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		rg[v].push_back(u);
	}
}
 
vector<int> curans;
inline void solve() {
	for (int i = 1; i <= n; i++) {
		if (lab1[i])
			continue;
		for (int j = 0; j < (signed) g[i].size(); j++)
			lab1[g[i][j]] = true;
		lab1[i] = true;
		curans.push_back(i);
	}
 
	for (int i = curans.size() - 1; ~i; i--) {
		int p = curans[i];
		lab2[p] = true;
		for (int j = 0; j < (signed) rg[p].size() && lab2[p]; j++)
			if (lab2[rg[p][j]])
				lab2[p] = false;
	}
 
	curans.clear();
	for (int i = 1; i <= n; i++)
		if (lab2[i])
			curans.push_back(i);
 
	printf("%d\n", (signed) curans.size());
	for (int i = 0; i < (signed) curans.size(); i++)
		printf("%d ", curans[i]);
}
 
int main() {
	init();
	solve();
	return 0;
}