#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
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
ll n, k, V[DIM];
int main()
{
	schnell;
	
	cin >> n >> k;
	forn(i, n) {
		ll x;
		cin >> x;
		V[x]++;
	}
	sort(V + 1, V + 1 + k);
	ll res = 0, cap = n / 2;
	if (n % 2 != 0)cap++;
	for (ll i = k; i >= 1; i--) {
		ll cof = V[i] / 2;
		cof = min(cof, cap);
		V[i] -= cof * 2;
		res += cof*2;
		cap -= cof;
	}
	for (ll i = k; i >= 1;i--) {
		if (V[i] == 1 && cap > 0) {
			cap--;
			res++;
		}
	}
	cout << res << endl;
}
// 1 1 1 1 1 1 1 1
// 8 4
//   A      A