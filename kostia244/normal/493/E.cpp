#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<20;
ll eval(vector<ll> coefs, ll x) {
	int n = coefs.size();
	ll sum = 0, pw = 1, cur;
	for(int i = 0; i < n; i++) {
		if(i && __builtin_mul_overflow(pw, x, &pw)) return -1;
		if(__builtin_mul_overflow(pw, coefs[i], &cur)) return -1;
		if(__builtin_add_overflow(cur, sum, &sum)) return -1;
	}
	return sum;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t, a, b;
	cin >> t >> a >> b;
	if((t == a) && (a != b)) return cout << "0\n", 0;
	if(a == 1 && b == 1 && t == 1) return cout << "inf\n", 0;
	int ans = 0;
	for(ll tk = 1, ak = 1; tk <= a && ak <= b;) {//P(x) = x^k * c
		ll C = a/tk;
		if(C*tk == a && C*ak == b) ans++;
		if(__builtin_mul_overflow(ak, a, &ak)) break;
		if(__builtin_mul_overflow(tk, t, &tk)) break;
	}
	if(a > 1) {
	vector<ll> coefs;
	for(ll tb = b;tb;tb/=a) coefs.push_back(tb%a);
	int nz = 0;
	for(auto i : coefs) nz += !!i;;
	if(nz>1) ans += eval(coefs, t) == a && eval(coefs, a) == b;
	}
	cout << ans << '\n';
	return 0;
}