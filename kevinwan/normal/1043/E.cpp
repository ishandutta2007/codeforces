#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pll a[300001];
ll ans[300001],pa[300001],pb[300001];
map<pll, int> back;
bool comp(pll &q, pll &w) { return q.first - q.second < w.first - w.second; }
int main() {
	int n, m,i,x,y;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%lld%lld", &a[i].first, &a[i].second), back[a[i]] = i;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		ll sub;
		if (a[x].first - a[x].second < a[y].first - a[y].second)sub = a[x].first + a[y].second;
		else sub = a[x].second + a[y].first;
		ans[x] -= sub, ans[y] -= sub;
	}
	sort(a + 1, a + n + 1, comp);
	for (i = 1; i <= n; i++)pa[i] = pa[i - 1] + a[i].first, pb[i] = pb[i - 1] + a[i].second;
	for (i = 1; i <= n; i++) {
		ll t;
		t = a[i].first*(n - i) + a[i].second*(i - 1);
		t += pa[i - 1] - pa[0];
		t += pb[n] - pb[i];
		ans[back[a[i]]] += t;
	}
	for (i = 1; i <= n; i++)printf("%lld ", ans[i]);
	getchar(); getchar();
}