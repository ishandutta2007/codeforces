#include <bits/stdc++.h>

using namespace std;
#define DIM 25
#define DIM2 400007
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
ll n, A[DIM];
int main()
{
	schnell;

	cin >> n;
	forn(i, n) {
		ll x; cin >> x;
		ll rozr = 1;
		while (x > 0) {
			ll g = x % 10;
			x /= 10;
			A[rozr] += g*n;
			A[rozr + 1] += g*n;
			A[rozr]%=MODULO;
			A[rozr+1]%=MODULO;
			rozr += 2;

		}
	}
	ll res = 0;
	for (ll i = 1; i <= DIM - 2; i++) {
		ll g = A[i];
		ll cof =1;
		forn(j,i-1){
		    cof*=10;
		cof %= MODULO;
		}
		g *= cof;
		g %= MODULO;
		res += g;
		res %= MODULO;
	}
	cout << res << endl;
}