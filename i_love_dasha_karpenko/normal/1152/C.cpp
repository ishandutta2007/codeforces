#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
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
ll a, b;
vector<ll> V;
ll __gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	while (y > 0) {
		x %= y;
		swap(x, y);
	}
	return x + y;
}
int main()
{
	schnell;
	cin >> a >> b;
	if (a > b)swap(a, b);
	ll c = b - a;
	for (ll i = 1; i*i <= c; i++) {
		if (c % i == 0) {
			V.pb(i);
			if (c % (c / i) == 0 && c / i != i)V.pb(c / i);
		}
	}
	ll res = INF, ans = 0;
	for (ll to : V) {
		if (a % to != b % to)continue;
		ll k;
		if (a % to == 0) {
			k = 0;
		}
		else {
			k = to - a % to;
		}
		ll r = (a + k) / __gcd(a + k, b + k) * (b + k);
		if (r < res) {
			res = r;
			ans = k;
		}
	}
	cout << ans << endl;
}
// (a+k)%(b+k)
// a-b*x;