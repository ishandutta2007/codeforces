#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ld = ll;
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
	if(x.real() == 0) {
		a = 1;
		b = 0;
		c = -y.real();
	} else {
		a = -x.imag();
		b = x.real();
		c = -(a*y.real() + b*y.imag());
	}
}

bool check(vector<vec>& v, vec x, vec y) {
	ld a, b, c;
	to_line(a, b, c, x, y);
	vector<vec> r;
	for(auto i : v)
		if(a*i.real() + b*i.imag() + c != 0)
			r.push_back(i);
	if(r.size() < 3)
		return true;
	to_line(a, b, c, r[0], r[1]);
	for(auto i : r)
		if(a*i.real() + b*i.imag() + c != 0)
			return false;
	return true;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if(n < 5) {
		cout << "YES";
		return 0;
	}
	vector<vec> a;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(int x, y, i = 0; i < 60; i++) {
		x = rng()%n;
		while((y = rng()%n) == x);
		if(check(a, a[x], a[y])) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}