#include <bits/stdc++.h>
#define mod(a,b) (a>=0?(a%b):(b-a%b))
using namespace std;
typedef long long ll;
const ll mod = 998244353;
multiset<ll> f;
ll a[1000],num[1000];
bool d[1000];
ll gcd(ll a, ll b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%lld", a + i),num[i]=1;
	for (i = 0; i < n; i++)for (j = i - 1; j >= 0; j--) {
		if (a[i] == a[j]) {
			num[i] += num[j];
			num[j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		ll rt = (ll)(pow(a[i], 0.25) + 0.1);
		if (rt*rt*rt*rt == a[i]) { f.insert(rt), f.insert(rt), f.insert(rt), f.insert(rt), d[i] = 1; continue; }
		rt = (ll)(pow(a[i], 0.33333333333333333333333333333) + 0.1);
		if (rt*rt*rt == a[i]) { f.insert(rt), f.insert(rt), f.insert(rt), d[i] = 1; continue; }
		rt = (ll)(pow(a[i], 0.5) + 0.1);
		if (rt*rt == a[i]) {  f.insert(rt), f.insert(rt), d[i] = 1; continue; }
	}
	ll ans = 1;
	for (i = 0; i < n; i++) {
		if (d[i])continue;
		for (j = 0; j < n; j++) {
			if (j == i)continue;
			ll g = gcd(a[i], a[j]);
			if (g == 1 ||g==a[i])continue;
			for(int k=0;k<num[i];k++)f.insert(g), f.insert(a[i] / g);
			d[i] = 1;
			break;
		}
		if (!d[i])ans *= (num[i]+1)*(num[i]+1), ans %= mod;
	}
	ll add = ans, ln = -1;
	for (ll k : f) {
		if (k != ln)ln = k, add = ans;
		ans += add, ans %= mod;
	}
	printf("%lld", ans);
	cout << endl;
	getchar(); getchar();
}