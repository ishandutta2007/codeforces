#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5 + 5;
ll a[MN];
int sn = 1;
int sgn(ll x) { return x >= 0?1:-1; }
typedef pair<ll, ll> pii;
int main() {
	ll n, k,i;
	ll x;
	scanf("%lld%lld%lld", &n, &k, &x);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (i = 0; i < n; i++)scanf("%lld", a + i),sn *= sgn(a[i]), pq.push({ abs(a[i]),i });
	while (k--) {
		int ind = pq.top().second,s=sgn(a[ind]);
		pq.pop();
		sn *= s;
		a[ind] -= sn*x;
		sn *= sgn(a[ind]);
		pq.push({ abs(a[ind]),ind });
	}
	for (i = 0; i < n; i++)printf("%lld ", a[i]);
}