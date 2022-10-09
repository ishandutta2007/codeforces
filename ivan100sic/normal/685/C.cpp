#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y, z;
} a[100005];
int n;

ll t[8];

ll dist(ll x, ll y, ll z) {
	ll d = 0;
	for (int mask=0; mask<8; mask++) {
		ll w = 0;
		if (mask & 1) w += x; else w -= x;
		if (mask & 2) w += y; else w -= y;
		if (mask & 4) w += z; else w -= z;
		d = max(d, t[mask] - w);
	}
	return d;
}

void solve() {
	cin >> n;
	fill(t, t+8, -3123123123123123123ll);

	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;


		for (int mask=0; mask<8; mask++) {
			ll w = 0;
			if (mask & 1) w += a[i].x; else w -= a[i].x;
			if (mask & 2) w += a[i].y; else w -= a[i].y;
			if (mask & 4) w += a[i].z; else w -= a[i].z;
			t[mask] = max(t[mask], w);
		}
	}

	if (n == 1) {
		cout << a[0].x << ' ' << a[0].y << ' ' << a[0].z << '\n';
		return;
	} /*else if (n == 2) {
		ll x = a[0].x + a[1].x;
		ll y = a[0].y + a[1].y;
		ll z = a[0].z + a[1].z;
		if (x % 2)
			x++;
		else if (y % 2)
			y++;
		else if (z % 2)
			z++;
		cout << x/2 << ' ' << y/2 << ' ' << z/2 << '\n';
		return;
	}*/

	// for (int i=0; i<8; i++)
	// 	cerr << t[i] << ' ';
	// cerr << '\n';

	ll x = 0, y = 0, z = 0, dd = dist(0, 0, 0);
	for (ll step=(1ll << 60); step > 0; step >>= 1) {
		int h = step == 1 ? 4 : 1;
		for (int i=0; i<h; i++) {
			for (int dx=-1; dx<=1; dx+=1)
			for (int dy=-1; dy<=1; dy+=1)
			for (int dz=-1; dz<=1; dz+=1)
			{
				ll x2 = x + dx * step;
				ll y2 = y + dy * step;
				ll z2 = z + dz * step;
				ll d = dist(x2, y2, z2);

				if (d < dd) {
					x = x2;
					y = y2;
					z = z2;
					dd = d;
				}
			}
		}
	}

	cout << x << ' ' << y << ' ' << z << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}