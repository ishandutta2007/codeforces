#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
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

void solve() {
	int a, b;
	string s;
	cin >> a >> b >> s;
	s+='X';
	int l = 0;
	vi seg;
	for(auto i : s) {
		if(i=='.')
			l++;
		else if(l)
			seg.pb(l), l = 0;
	}
	l = -1;
	int c = 0;
	for(auto i : seg) {
		if(i >= b && i < a) {
			cout << "NO\n";
			return;
		}
		if(i >= 2*b){
			if(l == -1)
				l = i;
			else {
				cout << "NO\n";
				return;
			}
		}
		if(i >= a && i < 2*b)
			c++;
	}
	if(l == -1) {
		cout << (c%2 ? "YES\n" : "NO\n");
		return;
	}
	bool ok = false;
	l -= a;
	if(l < 0) {
		cout << "NO\n";
		return;
	}
	for(int x = 0; x <= l; x++) {
		int y = l-x;
		if(x >= b && x < a) {
			continue;
		}
		if(y >= b && y < a) {
			continue;
		}
		if(x >= 2*b)
			continue;
		if(y >= 2*b)
			continue;
		if(x >= a && x < 2*b)
			c++;
		if(y >= a && y < 2*b)
			c++;
		ok|=(c&1)^1;
		if(x >= a && x < 2*b)
			c--;
		if(y >= a && y < 2*b)
			c--;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}