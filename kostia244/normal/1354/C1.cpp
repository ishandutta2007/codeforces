#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 80;

using ld = long double;
using vec = complex<ld>;

const ld tau = 6.28318530717958647692;
ld find(vec dir, int n) {
	vec pos(0, 0);
	ld lx = 0, rx = 0, ly = 0, ry = 0;
	vec step = polar((ld)1, tau/n);
	for(int i = 0; i < 2*n; i++) {
		lx = min(lx, pos.real());
		rx = max(rx, pos.real());
		ly = min(ly, pos.imag());
		ry = max(ry, pos.imag());
		pos += dir;
		dir *= step;
	}
	return max((rx-lx),(ry-ly));
}
void solve() {
	int n;
	cin >> n;
	n *= 2;
	ld l = 0, r = tau/n, x, y;
	while(r-l>1e-9) {
		x = l + (r-l)/3;
		y = r - (r-l)/3;
		if(find(polar((ld)1, x), n) > find(polar((ld)1, y), n))
			l = x;
		else
			r = y;
	}
	cout << fixed << setprecision(15) << find(polar((ld)1, l), n) << endl;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}
//0 1 0 1 0 1 0 1 2 2