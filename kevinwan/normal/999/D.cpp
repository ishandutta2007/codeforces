#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
int num[200000];
int p[200000];
void init() { for (int i = 0; i < 200000; i++)p[i] = i; }
int find(int x) { if (p[x] == x)return x; return p[x] = find(p[x]); }
void u(int x, int y) {
	p[y] = find(x);
}
int main() {
	int n,m,i,j;
	ll ans = 0;
	scanf("%d%d", &n,&m);
	init();
	for (i = 0; i < n; i++)scanf("%lld", a + i);
	for (i = 0; i < n; i++) {
		int mod = a[i] % m;
		int f = find(mod);
		ans += (f + m - mod) % m;
		a[i] += (f + m - mod) % m;
		num[f]++;
		if (num[f] == n / m)u((f + 1) % m, f);
	}
	printf("%lld\n", ans);
	for (i = 0; i < n; i++)printf("%lld ", a[i]);
	getchar(); getchar();
}