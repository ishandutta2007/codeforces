#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int mo = 998244353;
const int N = 1e5 + 10;

ll n, a[N], pw[35], cnt[55];

ll len(ll x) {
	ll l = 0;
	while(x) {
		l ++; x /= 10;
	}
	return l;
}

int main() {
	scanf("%I64d", &n);
	pw[0] = 1;
	for(ll i = 1; i <= 22; i ++) pw[i] = pw[i - 1] * 10ll % mo;
	ll ans = 0;
	for(ll i = 1; i <= n; i ++) {
		scanf("%I64d", a + i);
		cnt[len(a[i])] ++;
	}
	for(ll i = 1; i <= n; i ++) {
		ll l = len(a[i]);
		for(ll j = l; j <= 10; j ++) {
			ll ai = a[i], y = 0;
			while(ai) {
				ll x = ai % 10;
				ans = (ans + 1ll * x * pw[y] % mo * cnt[j] % mo) % mo;
				ans = (ans + 1ll * x * pw[y + 1] % mo * cnt[j] % mo) % mo;
				ai /= 10; y += 2;
			}
		}
		for(ll j = 1; j < l; j ++) {
			ll ai = a[i], y = 0;
			while(ai) {
				ll x = ai % 10;
				if(y >= 2 * j) {
					ans = (ans + 2ll * x * pw[y] % mo * cnt[j] % mo) % mo;
					ai /= 10; y ++;
					continue ;
				}
				ans = (ans + 1ll * x * pw[y] % mo * cnt[j] % mo) % mo;
				ans = (ans + 1ll * x * pw[y + 1] % mo * cnt[j] % mo) % mo;
				ai /= 10; y += 2;
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}