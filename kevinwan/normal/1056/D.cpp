#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<int> g[100001];
int l[100001];
vector<int> lis;
void dfs(int x) {
	for (int y : g[x]) {
		dfs(y);
		l[x] += l[y];
	}
	if (l[x] == 0)l[x] = 1;
	lis.push_back(l[x]);
}
int main() {
	int n;
	scanf("%d", &n);
	int i, x;
	for (i = 2; i <= n; i++)scanf("%d", &x), g[x].push_back(i);
	dfs(1);
	sort(lis.begin(), lis.end());
	for (i = 0; i < n; i++)printf("%d ", lis[i]);
	getchar(); getchar();
}