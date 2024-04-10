#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> to;
ll back[800001];
ll a[200001], b[200001];
set<ll> p;
ll c[800001];
ll ans[200001];
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%lld%lld", a + i, b + i), p.insert(a[i]), p.insert(b[i]),p.insert(a[i]+1),p.insert(b[i]+1);
	i = 1;
	for (auto x : p) {
		to[x] = i;
		back[i] = x;
		i++;
	}
	for (i = 0; i < n; i++)a[i] = to[a[i]], b[i] = to[b[i]];
	for (i = 0; i < n; i++)c[a[i]]++, c[b[i]+1]--;
	for (i = 1; i <= 800000; i++)c[i] += c[i - 1];
	for (i = 1; i < 800000; i++) {
		ans[c[i]] += back[i + 1] - back[i];
	}
	for (i = 1; i <= n; i++)printf("%lld ", ans[i]);
	getchar(); getchar();
}