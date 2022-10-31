#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 200007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
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
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}

ll A[DIM],Pref[DIM];
ll __gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	while (y > 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}
bool mc(ll x, ll y) {
	return x > y;
}
int main() {
	schnell;	
	ll q;
	cin >> q;

	forn(trrte, q) {
		ll n;
		cin >> n;
		forn(i, n)cin >> A[i];
		ll x, a, y, b, k;
		cin >> x >> a >> y >> b >> k;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		sort(A + 1, A + 1 + n,mc);
		ll g = a/__gcd(a, b)*b;
		forn(i, n)Pref[i] = Pref[i - 1] + A[i];
		ll res = -1;
		for (ll i = 0; i <= n; i++) {
			ll r = Pref[i / g]/100*(x+y);
			ll nextpos = i;
			ll mxa =nextpos / a-i/g;
			r += (Pref[i/g+mxa]-Pref[i / g])/100*x;
			ll mxb = nextpos / b - i / g;
			r += (Pref[i / g + mxa + mxb] - Pref[i / g + mxa]) / 100 * y;
			if (r >= k) {
				res = i;
				break;
			}
			
		}
		cout << res << endl;
	}
	return 0;
}