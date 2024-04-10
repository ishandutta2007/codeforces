#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int mn = 2e5 + 10;
set<int> g[mn];
int num,k;
bool ded[mn];
int a[mn], b[mn],ans[mn];
void check(int x) {
	if (ded[x])return;
	if (g[x].size() >= k)return;
	ded[x] = 1;
	num--;
	for (int y : g[x]) {
		g[y].erase(x);
		check(y);
	}
}
int main() {
	int n,m,i;
	scanf("%d%d%d", &n, &m, &k);
	num = n;
	for (i = 0; i < m; i++)scanf("%d%d", a+i,b+i), g[a[i]].insert(b[i]), g[b[i]].insert(a[i]);
	for (i = 1; i <= n; i++)check(i);
	ans[m] = num;
	for (i = m - 1; i >= 0; i--) {
		g[a[i]].erase(b[i]);
		g[b[i]].erase(a[i]);
		check(a[i]);
		check(b[i]);
		ans[i] = num;
	}
	for (i = 1; i <= m; i++)printf("%d\n", ans[i]);
}