#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;
const double eps = 1e-7;
using vec = complex<double>;
double dot(vec a, vec b) {
	return (conj(a) * b).real();
}
double cross(vec a, vec b) {
	return (conj(a) * b).imag();
}
istream& operator>>(istream &in, vec& x) {
	double a, b;
	in >> a >> b;
	x =vec(a, b);
	return in;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, id;
	vec a, b, x;
	cin >> a >> b >> x >> n;
	vector<vec> v;
	v.resize(n);
	double ans = 0;
	for(auto &i : v) cin >> i, ans += 2.*abs(i-x);
	vector<pair<double, int>> da, db;
	id = 0;
	for(auto i : v)
		da.pb({abs(i-a)-abs(i-x), id++});
	id = 0;
	for(auto i : v)
		db.pb({abs(i-b)-abs(i-x), id++});
	sort(all(da));
	sort(all(db));
	da.pb({0, -1});
	db.pb({0, -1});
	double diff = DBL_MAX;
	for(int i = 0; i < n; i++) {
		double t = da[i].first;
		if(da[i].second==db[0].second)
			t += min(.0, db[1].first);
		else
			t += min(.0, db[0].first);
		diff = min(diff, t);
	}
	swap(db, da);
	for(int i = 0; i < n; i++) {
		double t = da[i].first;
		if(da[i].second==db[0].second)
			t += min(.0, db[1].first);
		else
			t += min(.0, db[0].first);
		diff = min(diff, t);
	}
	cout << fixed << setprecision(15) << ans+diff;
}