#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 6969701591;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using vec = complex<ll>;
using vecld = complex<ld>;
const ll inf = 1e18;
ll dot(vec a, vec b) {
	return (conj(a) * b).real();
}
ld dotld(vecld a, vecld b) {
	return (conj(a) * b).real();
}
ll cross(vec a, vec b) {
	return (conj(a) * b).imag();
}
ld crossld(vecld a, vecld b) {
	return (conj(a) * b).imag();
}
vecld tod(vec x) {
	return vecld(x.real(), x.imag());
}
struct cht {
	vector<vec> v;
	bool to_remove() {
		int n = v.size();
		if (n < 3)
			return false;
		return crossld(tod(v[n - 2] - v[n - 3]), tod(v[n - 1] - v[n - 2])) < 1e-8;
	}
	void add(vec x) {
		v.pb(x);
		while (to_remove())
			swap(v.back(), v[v.size() - 2]), v.pop_back();
	}
	bool worse(int a, int b, vec x) {
		vecld u(v[a].real(), v[a].imag());
		vecld z(v[b].real(), v[b].imag());
		vecld xx(x.real(), x.imag());
		return dotld(u, xx) > dotld(z, xx);
	}
	ll get(vec x) {
		ll lo = 0, hi = (ll) v.size() - 1;
		ll a, b, ans = 1e18;
		while (hi - lo > 4) {
			a = lo + (hi - lo + 1) / 3;
			b = hi - (hi - lo + 1) / 3;
			if (worse(a, b, x))
				lo = a;
			else
				hi = b;
		}
		while (lo <= hi) {
			vecld xx(x.real(), x.imag());
			vecld yy(v[lo].real(), v[lo].imag());
			if (dotld(xx, yy) <= (ld) ans+1000)
				ans = min(ans, dot(x, v[lo]));
			lo++;
		}
		return ans;
	}
};
ll n, a[100400], b[100400], dp[100400];

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	cht c;
	c.add(vec(0, b[1]));
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		ans = c.get(vec(1, a[i]));
		c.add(vec(ans, b[i]));
	}
	cout << ans;
}