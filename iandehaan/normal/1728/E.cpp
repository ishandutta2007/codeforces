#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

#define MAXN 300'010

ll a[MAXN];
ll b[MAXN];
vector<ll> reds;
vector<ll> blacks;
vector<ll> rpref;
vector<ll> bpref;
ll total = 0;

ll inf = 1e7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(i, 0, n) {
		//cout << "reading " << i << endl;
		cin >> a[i] >> b[i];
		//cout << a[i] << ' ' << b[i] << endl;
	}

	rep(i, 0, n) {
		total += max(a[i], b[i]);
		if (a[i] >= b[i]) {
			// red
			reds.pb(a[i]-b[i]);
		} else {
			blacks.pb(b[i]-a[i]);
		}
	}
	//cerr << "what?" << endl;
	sort(all(reds));
	sort(all(blacks));
	//cerr << "what2" << endl;
	rpref.resize(sz(reds));
	//cerr << "aint no way" << endl;
	//cerr << sz(blacks) << endl;
	bpref.resize(sz(blacks));
	//cerr << "lawjfalwkj" << endl;
	//cout << sz(reds) << endl;
	if (sz(reds) > 0) rpref[0] = reds[0];
	//cerr << "frick you" << endl;
	rep(i, 1, sz(reds)) rpref[i] = rpref[i-1] + reds[i];
	//cerr << "fuck you" << endl;
	if (sz(blacks) > 0) bpref[0] = blacks[0];
	rep(i, 1, sz(blacks)) bpref[i] = bpref[i-1] + blacks[i];

	int m;
	cin >> m;
	//cout << "m = " << m << endl;
	while (m--) {
		//cerr << m << endl;
		// find the closets we can get to (sz(reds), sz(blacks)). if we hit it exactly, yay!
		// otherwise get as close as possible on each side
		// (sz(reds)-eps), sz(blacks)+eps)
		// we lose the value on reds[0, eps]
		// (sz(reds)+eps'), sz(blacks)-eps')
		// we lose the value on blacks[0, eps']

		ll out = -1;
		ll c1, c2;
		cin >> c1 >> c2;

		ll d, x, y;
		d = euclid(c1, c2, x, y);
		if (n % d != 0) {
			cout << -1 << '\n';
			continue;
		}
		x *= n/d;
		y *= n/d;
		//cout << x*c1 << ' ' << y*c2 << endl;

		// (sz(reds)-eps), sz(blacks)+eps)
		ll lo = -1*inf - 1;
		ll hi = inf + 1;
		//cerr << lo << ' ' << hi << endl;
		while (hi-lo > 1) {
			ll mid = (hi+lo)/2;
			ll xx = x - (mid*c2)/d;
			if (xx*c1 < sz(reds)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}


		for (ll k = hi+1; k >= lo-1; k--) {
			ll amtred = (x - (k*c2)/d)*c1;
			ll amtblack = (y + (k*c1)/d)*c2;

			if (amtred < 0 || amtblack < 0) continue;

			ll inbalancered = sz(reds)-amtred;
			ll inbalanceblack = sz(blacks)-amtblack;
			ll loss = 0;
			if (inbalancered > 0) {
				loss += rpref[inbalancered-1];
			}
			if (inbalanceblack > 0) {
				loss += bpref[inbalanceblack-1];
			}
			//cout << amtred << ' ' << amtblack << ' ' << total << ' ' << loss << endl;
			out = max(out, total-loss);
		}
		cout << out << '\n';

		
		

		// let d = gcd(a, b)
		// one solution: (x - b/d, y + a/d) ( to hit d)
		// so solution to hit n is
		// ((n/d)*(x - b/d), (n/d)*(y + a/d))
		// ((n/d)*(x - kb/d), (n/d)*(y+ka/d))

		// initial solution is (x, y)
		// (x - kb/d, y + ka/d)
		// so find initial solution and binary search over k

	}
}