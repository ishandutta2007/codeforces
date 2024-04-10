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
ll n, m, k, A[DIM], pref[DIM],mxpref[11];
int main()
{
	schnell;
	cin >> n >> m >> k;
	forn(i, n) {
		cin >> A[i];
		pref[i] = A[i] + pref[i - 1];
	}
	ll res = 0;
	for (ll i = 0; i < m; i++) {
		mxpref[i] = -INF;
	}
	forn(i, n) {
		ll cof = i / m;
		ll cof1 = (i + 1) / m;
		mxpref[i%m] = max(mxpref[i%m], k * cof-pref[i - 1]);
		for (ll j = 0; j < m; j++) {
			if ((i+1) % m <= j) {
				res = max(res, mxpref[j] + pref[i] - cof1 * k);
			}
			else {
				res = max(res, mxpref[j] + pref[i] - (cof1 + 1) * k);
			}
		}
	}
	cout << res << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;