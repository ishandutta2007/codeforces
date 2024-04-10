#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
bool pri(ll x) {
	for (ll i = 2; i*i <= x; i++)if (x%i == 0)return 0;
	return 1;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		ll ln = n;
		while (!pri(ln + 1))ln--;
		ll den = 2 * (ln + 1), num = ln - 1;
		ll nxt = ln+2;
		while (!pri(nxt))nxt++;
		den *= nxt, num *= nxt;
		num += 2 * (n - ln);
		ll g = gcd(num, den);
		num /= g, den /= g;
		printf("%lld/%lld\n",num, den);
	}
}