#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> g[200001];
set<int> av;
vector<int> st;
void dfs(int x) {
	av.erase(x);
	for (set<int>::iterator it = av.begin(); it != av.end();) {
		int y = *it;
		if (g[x].find(y) != g[x].end()) {
			it++; continue;
		}
		dfs(y);
		it = av.upper_bound(y);
	}
}
int main() {
	int n,m,i,a,b;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++)av.insert(i);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].insert(b);
		g[b].insert(a);
	}
	for (i = 1; i <= n; i++) {
		if (av.find(i) == av.end())continue;
		int beg = av.size();
		dfs(i);
		st.push_back(beg - av.size());
	}
	printf("%d\n", st.size());
	sort(st.begin(), st.end());
	for (int x : st)printf("%d ", x);
	getchar(); getchar();
}