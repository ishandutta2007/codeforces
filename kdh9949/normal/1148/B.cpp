#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;
const ll INF = ll(1e18);

int n, m, k;
ll ta, tb, a[N], b[N], r;

int main(){
	scanf("%d%d%lld%lld%d", &n, &m, &ta, &tb, &k);
	if(k >= min(n, m)){ puts("-1"); return 0; }
	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	for(int i = 0; i < m; i++) scanf("%lld", b + i);
	sort(a, a + n);
	sort(b, b + m);
	for(int i = 0; i <= k; i++){
		ll x = a[i] + ta;
		int t = int(lower_bound(b, b + m, x) - b) + (k - i);
		if(t >= m) r = INF;
		else r = max(r, b[t] + tb);
	}
	if(r == INF) puts("-1");
	else printf("%lld\n", r);
}