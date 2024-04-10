#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

ll query(ll a, ll b) {
	cout << "SCAN " << a << ' ' << b << endl;
	G(res) return res;
}

ll dig(ll a, ll b) {
	cout << "DIG " << a << ' ' << b << endl;
	G(res) return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(tc) while(tc--) {
		G(n) G(m)
		ll a = query(1, 1), b = query(1, m);
		ll c = 2 * (n + m - 2) - b;
		ll xs = (a + b - 2 * (m - 1)) / 2 + 2;
		ll ys = (a + c - 2 * (n - 1)) / 2 + 2;
		ll d = query(xs / 2, 1) - (ys - 2), e = query(1, ys / 2) - (xs - 2);
		ll x1 = xs / 2 - d / 2, x2 = xs / 2 + (d + 1) / 2;
		ll y1 = ys / 2 - e / 2, y2 = ys / 2 + (e + 1) / 2;
		if(!dig(x1, y1)) dig(x1, y2), dig(x2, y1);
		else dig(x2, y2);
	}
}