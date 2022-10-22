#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int a[100001], b[100001], c[100001];
int num, ans[100001], cnt[1001];
bitset<1001> s[1001];
bitset<1001> swi;
vector<int> g[100001];
int m;
void dfs(int x) {
	bool ad = 0, re = 0;
	if (a[x] == 1 && !s[b[x]][c[x]])ad = 1;
	else if (a[x] == 2 && s[b[x]][c[x]])re = 1;
	else if (a[x] == 3)num += m - 2 * cnt[b[x]], cnt[b[x]] = m - cnt[b[x]], s[b[x]] ^= swi;
	if (ad)num++, cnt[b[x]]++, s[b[x]][c[x]] = 1;
	if (re)num--, cnt[b[x]]--, s[b[x]][c[x]] = 0;
	ans[x] = num;
	for (int y : g[x])dfs(y);
	if (ad)num--, cnt[b[x]]--, s[b[x]][c[x]] = 0;
	if (re)num++, cnt[b[x]]++, s[b[x]][c[x]] = 1;
	if (a[x] == 3)num += m - 2 * cnt[b[x]], cnt[b[x]] = m - cnt[b[x]], s[b[x]] ^= swi;
}
int main() {
	swi.set();
	int n, q, i;
	scanf("%d%d%d", &n, &m, &q);
	for (i = 1; i <= q; i++) {
		scanf("%d%d", a + i, b + i);
		if (a[i] <= 2)scanf("%d", c + i);
		if (a[i] == 4)g[b[i]].push_back(i);
		else g[i - 1].push_back(i);
	}
	dfs(0);
	for (i = 1; i <= q; i++)printf("%d\n", ans[i]);
}