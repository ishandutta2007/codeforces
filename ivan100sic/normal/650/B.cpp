#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, t, a, b, sol;
string s;
ll z[1000005];

ll cost(ll x0, ll x, ll y) {
	// skrolujes levo od x0 do x i onda gledas sve slike zakljucno sa y
	return b*(z[max(x0, y)+1]-z[x]) + a*((x0-x) + (y-x)) + (y-x+1);
}

void solve(ll x0) {
	for (ll i=0; i<2*n; i++)
		z[i+1] = z[i] + (s[i] == 'w');

	ll y = x0;
	if (cost(x0, x0, y) > t) {
		y = -1;
	} else {
		while (1) {
			if (y+1 < 2*n && cost(x0, x0, y+1) <= t)
				y++;
			else
				break;
		}
	}

	if (y != -1)
		sol = max(sol, y-x0+1);

	for (ll x=x0; x>=0; x--) {
		if (y == -1) {
			// probaj da krenes od x i da se siris
			if (cost(x0, x, x) > t) {
				y = -1;
			} else {
				y = x;
				while (1) {
					if (y+1 < 2*n && cost(x0, x, y+1) <= t)
						y++;
					else
						break;
				}
			}
		} else {
			// smanjuj dok ne padne ispod t
			while (1) {
				if (y >= x && cost(x0, x, y) > t)
					y--;
				else
					break;
			}
			if (y < x)
				y = -1;
		}

		// cerr << "xy " << x << ' ' << y << ' ' << (y == -1 ? -1 : cost(x0, x, y)) << '\n';

		if (y != -1)
			sol = max(sol, y-x+1);

		// spremi se da dodas x-1
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b >> t >> s;
	s += s;

	solve(n);
	reverse(s.begin(), s.end());
	solve(n-1);

	cout << min(sol, n) << '\n';
	
}