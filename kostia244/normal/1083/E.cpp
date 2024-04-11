#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("trapv")
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
ll dot(vec a, vec b) {
	return (conj(a) * b).real();
}
ll cross(vec a, vec b) {
	return (conj(a) * b).imag();
}
struct cht {
	vector<vec> upper, lower;
	bool to_lremove(vector<vec> &hull) {
		int n = hull.size();
		if (n < 3)
			return false;
		vecld n1(hull[n - 1].real(), hull[n - 1].imag());
		vecld n2(hull[n - 2].real(), hull[n - 2].imag());
		vecld n3(hull[n - 3].real(), hull[n - 3].imag());
		return (conj(n2 - n3)*(n1 - n2)).imag() < 0;
	}
	bool to_rremove(vector<vec> &hull) {
		int n = hull.size();
		if (n < 3)
			return false;
		vecld n1(hull[n - 1].real(), hull[n - 1].imag());
		vecld n2(hull[n - 2].real(), hull[n - 2].imag());
		vecld n3(hull[n - 3].real(), hull[n - 3].imag());
		return (conj(n2 - n3)*(n1 - n2)).imag() > 0;
	}
	void add(vec x) {
		upper.pb(x);
		while (to_rremove(upper))
			swap(upper.back(), upper[upper.size() - 2]), upper.pop_back();
		lower.pb(x);
		while (to_lremove(lower))
			swap(lower.back(), lower[lower.size() - 2]), lower.pop_back();
	}
	ll get(vector<vec> &hull, vec x) {
		if(hull.size()==1) {
			return dot(hull.back(), x);
		}
		ll lo = 0, hi = (int) hull.size() - 1, a, b, ans = 0, t = (dot(x, hull[0])<dot(x, hull[1]));
		while (hi - lo > 4) {
			a = lo + (hi - lo + 1) / 2;
			if ((dot(x, hull[a]) < dot(x, hull[a+1]))==t)
				lo = a;
			else
				hi = a;
		}
		while (lo <= hi)
			ans = max(ans, dot(x, hull[lo++]));
		return max({ans, dot(hull.back(), x), dot(hull[0], x)});
	}
	ll get(vec x) {
		return get(upper, x);
	}
};
struct obj {
	ll x, y, a;
	bool operator<(const obj& o) {
		return x < o.x;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll x[1000100], y[1000100], a[1000100];
	vector<obj> s(n);
	for (int i = 1; i <= n; i++)
		cin >> s[i - 1].x >> s[i - 1].y >> s[i - 1].a;
	sort(all(s));
	for (int i = 1; i <= n; i++)
		x[i] = s[i - 1].x, y[i] = s[i - 1].y, a[i] = s[i - 1].a;
	cht c;
	ll ans = 0, t;
	c.add(vec(0, 0));
	for (int i = 1; i <= n; i++) {
		t = c.get(vec(-y[i], 1)) + x[i] * y[i] - a[i];
		ans = max(ans, t);
//		cout << c.hull.size() << " ";
		c.add(vec(x[i], t));
	}
	cout << ans;

}