#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
const ll mod = 998244353ll;
ll dx = 1, dy = 1, x = 0, y = 0, n, m, stop = 0, k, pos = 0;

struct pt {
	ll x, y, i;
	pt(ll x = -1, ll y = -1, ll i = -1) {
		this->x = x;
		this->y = y;
		this->i = i;
	}
	bool operator<(const pt &rhs) const {
		return i < rhs.i;
	}
};

void go() {
	ll t = INT_MAX;
	if (dx == 1)
		t = min(t, n - x);
	else
		t = min(t, x);
	if (dy == 1)
		t = min(t, m - y);
	else
		t = min(t, y);
	x += dx * t;
	y += dy * t;
	pos += t;
	if (x == n)
		dx *= -1;
	if (x == 0)
		dx *= -1;
	if (y == m)
		dy *= -1;
	if (y == 0)
		dy *= -1;
	if (x == n && y == m) {
		stop = 1;
	}
	if (x == 0 && y == m) {
		stop = 1;
	}
	if (x == n && y == 0) {
		stop = 1;
	}
	if (x == 0 && y == 0) {
		stop = 1;
	}
}
ll ans[200200], bias = 100100;
set<pt> diag[200200], adiag[200200];

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll x, y, i = 0; i < k; i++) {
		cin >> x >> y;
		ans[i] = -1;
		pt t(x, y, i);
		diag[x+y].insert(t);
//		cout << x << " " << y << " " << x+y << "\n";
		adiag[bias+x-y].insert(t);
	}
	while(!stop) {
		if(dx != dy) { // adiag
//			cout << "a ";
			ll p = x+y;
//			cout << p << " ";
			for(auto i : diag[p])
				adiag[bias+i.x-i.y].erase(i), ans[i.i] = pos + abs(x-i.x);
			diag[p].clear();
		} else { // diag
			ll p = bias+x-y;
//			cout << "d ";
			for(auto i : adiag[p])
				diag[i.x+i.y].erase(i), ans[i.i] = pos + abs(x-i.x);
			adiag[p].clear();
		}
//		cout << x << " " << y << "\n";
		go();
	}
//	cout << x << " " << y << "\n";
	for (ll i = 0; i < k; i++)
		cout << ans[i] << "\n";
}