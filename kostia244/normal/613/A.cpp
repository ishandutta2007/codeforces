#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ld = long double;
using vec = complex<ld>;
const ld eps = 1e-7;
ld dot(vec a, vec b) {
	return (conj(a)*b).real();
}
ld cross(vec a, vec b) {
	return (conj(a)*b).imag();
}
istream& operator>>(istream& in, vec& p) {
	ld x, y;
	in >> x >> y;
	p = vec(x, y);
	return in;
}
void to_line(ld &a, ld &b, ld &c, vec x, vec y) {
	x -= y;
	if(fabs(x.real()) < eps) {
		a = 1;
		b = 0;
		c = -y.real();
	} else {
		a = -x.imag()/x.real();
		b = 1;
		c = -(a*y.real() + b*y.imag());
	}
}
ld line_pt_dist(vec x, vec y, vec p) {
	if(dot(y-x, p-x) < eps)
		return abs(p-x);
	if(dot(x-y, p-y) < eps)
		return abs(p-y);
	ld a, b, c;
	to_line(a, b, c, x, y);
	ld ans = fabs(a*p.real() + b*p.imag() + c);
	ans /= abs(vec(a, b));
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(15);
	int n;
	vec p;
	cin >> n >> p;
	vector<vec> a;
	a.resize(n);
	for(auto &i : a) cin >> i;
	a.push_back(a[0]);
	ld rmin = 1e18, rmax = 0;
	for(int i = 1; i < a.size(); i++) {
		ld v = line_pt_dist(a[i-1], a[i], p);
		rmin = min(rmin, v);
		rmax = max(rmax, v);
		v = abs(a[i]-p);
		rmin = min(rmin, v);
		rmax = max(rmax, v);
	}
	cout << M_PI*(rmax*rmax - rmin*rmin);
}