#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 2e5+10;
int c[mn];
int p[mn];
ll inv(ll x) {
	ll ans = 1;
	for (ll i = mod - 2; i; i >>= 1, x = x * x%mod)if (i & 1)ans = ans * x%mod;
	return ans;
}
ll cur,cnt,bit[mn],tot,inc[mn],de[mn];
void up(int a, int b) { for (; a < mn; a += a & -a)bit[a] += b; }
ll qu(int a) { ll b = 0; for (; a; a -= a & -a)b += bit[a]; return b; }
int main() {
	int n,i,j,am;
	scanf("%d", &n);
	am = n;
	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
		c[i + 1]++;
		if (p[i] != -1)c[p[i]]--,am--;
	}
	inc[0] = c[0];
	de[n] = c[n];
	for (i = 1; i <= n; i++)inc[i] = inc[i - 1] + c[i];
	for (i = n - 1; i >= 0; i--)de[i] = de[i + 1] + c[i];
	for (i = n-1; i>=0; i--) {
		if (p[i] != -1) {
			tot += qu(p[i]);
			up(p[i], 1);
		}
	}
	tot %= mod;
	for (i = 0; i < n; i++) {
		if (p[i] != -1) {
			cnt += inc[p[i]];
			cnt %= mod;
		}
		else {
			cur += cnt;
			cur %= mod;
		}
	}
	cnt = 0;
	for (i = n - 1; i >= 0; i--) {
		if (p[i] != -1) {
			cnt += de[p[i]];
			cnt %= mod;
		}
		else {
			cur += cnt;
			cur %= mod;
		}
	}
	tot += cur * inv(am);
	tot %= mod;
	tot += 1LL*am *(am-1)%mod* inv(4);
	tot %= mod;
	printf("%lld", tot);
}