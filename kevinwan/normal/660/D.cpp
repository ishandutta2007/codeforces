#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
void exgcd(int a, int b, int* aa, int *bb) {
	int x, y;
	if (a == 0) { *aa = 0, *bb = 1; return; }
	exgcd(b%a, a, &x, &y);
	*bb = x;
	*aa = y + x * (b / a);
}
ll x[2000], y[2000];
map<pll, ll> ma;
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%lld%lld", x + i, y + i);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			ma[{x[i] + x[j], y[i] + y[j]}]++;
		}
	}
	ll ans=0;
	for (auto a : ma) {
		ans += (a.second - 1)*a.second / 2;
	}
	printf("%lld", ans);
}