#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 2007
#define DIM2 10007
#define MODULO 1000000007  
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ld fi, sc;
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
ll n;
ll __gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	while (y > 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}
int main() {
	schnell;
	cin >> n;
	ll g;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		if (i == 0)g = x;
		g = __gcd(g, x);
	}
	ll res = 0;
	for (ll i = 1; i <= sqrt(g); i++) {
		if (g % i == 0) {
			if (i * i == g)res++;
			else res += 2;
		}
	}
	cout << res << endl;
	return 0;
}