#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 3007
#define DIM2 DIM*150
#define MODULO 1000000007
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const ll INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}

int main() {
	schnell;
	ll t;
	cin >> t;
	forn(e, t) {
		ll b, p, f;
		cin >> b >> p >> f;
		ll h, c; cin >> h >> c;
		ll res = 0;
		if (h > c) {
			ll cof = min(p, b / 2);
			res += cof * h;
			b -= cof * 2;
			res += min(f, b / 2) * c;
		}
		else {
			ll cof = min(f, b / 2);
			res += cof * c;
			b -= cof * 2;
			res += min(b / 2, p) * h;
		}
		cout << res << endl;
	}
	return 0;
}