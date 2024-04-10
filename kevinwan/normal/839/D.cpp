#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> f[1000001];
ll mod = 1e9 + 7;
ll num[1000001];
const int mn = 1e6;
ll p(ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a%mod)if (b & 1)ans = ans * a%mod;
	return ans;
}
int main() {
	int n, i, j;
	for (i = 2; i <= mn; i++)for (j = i; j <= mn; j += i)f[j].push_back(i);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		for (int y : f[x])num[y]++;
	}
	for (i = 2; i <= mn; i++)num[i] = p(2,mod-2+num[i])*num[i]%mod;
	for (i = mn; i >= 2; i--)for (j = 2 * i; j <= mn; j += i)num[i] = (num[i] - num[j]) % mod;
	ll ans = 0;
	for (i = 2; i <= mn; i++)ans = (ans + num[i] * i) % mod;
	if (ans < 0)ans += mod;
	printf("%lld", ans);
}