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
	return (conj(a) * b).real();
}
ld cross(vec a, vec b) {
	return (conj(a) * b).imag();
}
istream& operator>>(istream& in, vec& p) {
	ld x, y;
	in >> x >> y;
	p = vec(x, y);
	return in;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, ans = 0;
	map<pair<ll, ll>, ll> q;
	cin >> n;
	vector<pair<ll, ll>> a;
	a.resize(n);
	for(auto &i : a) cin >> i.first >> i.second, i.first<<=1, i.second<<=1;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			ans += q[{(a[i].first+a[j].first)>>1, (a[i].second+a[j].second)>>1}]++;
	cout << ans;
}