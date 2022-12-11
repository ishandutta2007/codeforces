#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct Node {
	ll v, id;
	bool operator < (const Node &b) const {
		return v < b.v;
	}
} a[N];
int n;
ll A, cf, cm, m, ans[N], res(-1), pos, mv, pre[N];
bool check(ll m, int k, ll to) {
	return to * k - pre[k] <= m;
}
bool cmp(ll x, Node y) {
	return x < y.v;
}
int main() {
	scanf("%d%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i].v); a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i].v;
	if(check(m, n, A)) {
		printf("%lld\n", cf * n + A * cm);
		for(int i = 1; i <= n; i ++)
			printf("%lld ", A);
		return 0;
	}
	ll sum = 0, nw;
	for(int i = n + 1; i >= 1; i --) {
		if(i != n + 1) sum += A - a[i].v;
		ll l = 0, r = A, mid, ans = -1;
		while(l <= r) {
			mid = (l + r) >> 1;
			int j = upper_bound(a + 1, a + i, mid, cmp) - a - 1;
			if(j < 0) j = 0;
			if(check(m - sum, j, mid)) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		if(~ ans && m >= sum) {
			nw = ans * cm + (n + 1 - i) * cf;
			if(res < nw) { res = nw; pos = i; mv = ans; }
		}
	}
	for(int i = 1; i < pos; i ++) ans[a[i].id] = max(mv, a[i].v);
	for(int i = pos; i <= n; i ++) ans[a[i].id] = A;
	printf("%lld\n", res);
	for(int i = 1; i <= n; i ++) printf("%lld ", ans[i]);
	return 0;
}