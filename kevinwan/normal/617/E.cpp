#include <bits/stdc++.h>
#define SIZE 300
using namespace std; 
typedef long long ll;
struct query {
	int l, r, ind;
};
bool comp(const query&a, const query&b) { if (a.l / SIZE < b.l / SIZE)return 1; if (a.l / SIZE == b.l / SIZE && a.r < b.r)return 1; return 0; }
int num[1<<21], a[100001];
ll ans[100000];
query q[100000];
int main() {
	int n, m, k,i;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 1; i <= n; i++)scanf("%d", a + i),a[i]^=a[i-1];
	for (i = 0; i < m; i++)scanf("%d%d", &q[i].l, &q[i].r),q[i].ind=i;
	sort(q, q + m, comp);
	ll cur = 0;
	int lp = 1, rp = 0,l,r;
	for (i = 0; i < m; i++) {
		l = q[i].l-1, r = q[i].r;
		while (lp > l)lp--, cur += num[k^a[lp]], num[a[lp]]++;
		while (lp < l)num[a[lp]]--, cur -= num[k^a[lp]], lp++;
		while (rp < r)rp++, cur += num[k^a[rp]], num[a[rp]]++;
		while (rp > r)num[a[rp]]--, cur -= num[k^a[rp]], rp--;
		ans[q[i].ind] = cur;
	}
	for (i = 0; i < m; i++)printf("%lld\n", ans[i]);
	getchar(); getchar();
}