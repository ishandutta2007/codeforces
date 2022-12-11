#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
ll a[N], ans;
void attempt(ll p) {
	ll res = 0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] <= p) res += p - a[i];
		else res += min(a[i] % p, p - a[i] % p); 
		if(res >= ans) break ;
	}
	ans = min(res, ans);
}
void calc(ll x) {
	if(x <= 1) return ;
	for(ll i = 2; i * i <= x; i ++) {
		if(x % i == 0) {
			attempt(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) attempt(x);
}
int main() {
	scanf("%d", &n); srand(19260817);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", a + i);
		ans += a[i] & 1;
	}
	random_shuffle(a + 1, a + n + 1);
	for(int t = 0; t < 20; t ++) {
		ll x = a[rand() % n + 1];
		calc(x); calc(x - 1); calc(x + 1);
	}
	printf("%lld\n", ans);
	return 0;
}