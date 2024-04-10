#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define DIM2 200007
#define DIM3 200007
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef  long long ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
const ll MC = 5007;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n, k,a,b;
ll __gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	while (y > 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}
pll dist(ll x) {
	ll f1 = k - b, f2 = k + b;
	if (f1 <= x)f1 += k;
	if (f2 <= x)f2 += k;
	ll j1 = f1 - x, j2 = f2 - x,lap = n*k;
	ll mx = -INF, mi = INF;
	fore(0,i, n-1) {
		ll r1 = (j1 + k * i) % (n * k), r2 = (j2 + k * i) % (n * k);
		while (r1 == 0) {
			r1 = lap;
		}
		while (r2 == 0) {
			r2 = lap;
		}
		ll l1 = lap / __gcd(lap, r1) , l2 = lap / __gcd(lap, r2);
		mi = min(min(l1, l2), mi);
		mx = max(max(l1, l2), mx);
	}
	return { mi,mx };
}
int main()
{
	schnell;
	cin >> n >> k >> a >> b;
	pll r1 = dist(k - a);
	pll r2 = dist(k + a);
	cout << min(r1.first, r2.fi) << ' ' << max(r1.sc, r2.sc) << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;