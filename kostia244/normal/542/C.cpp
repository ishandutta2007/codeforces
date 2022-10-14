#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 303;
int n, a[maxn], l[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll mn = 1, mul = 1;
	for(int i = 1; i <= n; i++) {
		ll j = i, k = 0;
		for(; k <= n;) {
			j = a[j], k++;
			l[i] |= j==i;
			if(l[i]) break;
		}
		if(l[i]) mul = mul*(k/__gcd(mul, (ll)k));
	}
	for(int i = 1; i <= n; i++) {
		ll d = 0, j = i;
		while(!l[j]) d++, j = a[j];
		mn = max(mn, d);
	}
	if(mn%mul) mn -= mn%mul, mn += mul;
	cout << mn << '\n';
}