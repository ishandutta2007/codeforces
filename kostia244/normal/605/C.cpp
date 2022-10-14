//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld = long double;
int n, p, q;
vector<pi> t, a, b;
int C = 35;
ld eval(pi &a, pi& b, ld t) {
	ld x = a.first * t + b.first * (1. - t);
	ld y = a.second * t + b.second * (1. - t);
	return max((ld) p / x, (ld) q / y);
}
ld mint(pi& a, pi& b) {
	ld l = 0, lm, rm, r = 1;
	for(int i = 0; i < 600; i++) {
		lm = l + (r - l) / 3;
		rm = r - (r - l) / 3;
		if (eval(a, b, lm) > eval(a, b, rm))
			l = lm;
		else
			r = rm;
	}
	return eval(a, b, l);
}
ll cross(const pi& a, const pi& b) {
	return a.first * b.second - b.first * a.second;
}
bool ccw(pi &a, pi& b, pi& c) {
	pi t = {-a.first + b.first, -a.second + b.second};
	pi z = {-b.first + c.first, -b.second + c.second};
	return cross(t, z)>=0;
}
void hull(vector<pi> &a) {
	vector<pi> hull;
	for (int i = n; i--;) {
		if (a.back() > a[i])
			swap(a.back(), a[i]);
	}
	hull.pb(a.back());
	a.pop_back();
	sort(all(a), [](const pi& a, const pi& b) {
		return cross(a, b) < 0 || (cross(a, b)==0&&a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second);
	});
	for (auto i : a) {
		while (hull.size() > 1
				&& ccw(hull[hull.size() - 2], hull[hull.size() - 1], i))
			hull.pop_back();
		hull.pb(i);
	}
	a = hull;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p >> q;
	t.resize(n);
	ll ma = 0, mb = 0;
	for (auto &i : t) {
		cin >> i.first >> i.second;
		ma = max(ma, i.first);
		mb = max(mb, i.second);
	}
	t.pb({0, 0});
	t.pb({ma, 0});
	t.pb({0, mb});
	hull(t);
	ld ans = DBL_MAX;
	t.pb(t[0]);
	for(int i = 1; i < t.size(); i++) {
//		cout << t[i].first << " " << t[i].second << "\n";
		ld x = mint(t[i-1], t[i]);
		if(x-ans < 1e-8)
		ans = x;
	}
	cout << fixed << setprecision(15) << ans;
}