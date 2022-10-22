#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
struct Edge {
	int a, b;
}Ed[201000];
vector<int>E[201000];
int Col[201000], Res[201000];
void DFS(int a, int c) {
	Col[a] = c;
	for (auto &x : E[a]) {
		if (!Col[x])DFS(x, 3 - c);
	}
}
int main() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
		Ed[i] = { a,b };
	}
	for (i = 1; i <= n; i++) {
		if (!Col[i])DFS(i, 1);
	}
	for (i = 0; i < m; i++) {
		if (Col[Ed[i].a] + Col[Ed[i].b] != 3) {
			puts("NO");
			return 0;
		}
		Res[i] = Col[Ed[i].a] - 1;
	}
	puts("YES");
	for (i = 0; i < m; i++)printf("%d", Res[i]);
}