#include <bits/stdc++.h>

using namespace std;
#define DIM 57
#define DIM2 DIM*DIM
#define DIM3 200007
#define INF 10E10
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

typedef long long ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n, A[DIM], pref[DIM];
vector<pll> ans;
set<ll> S;
ll findsum(ll r, ll pos) {
	ll res = 1;
	for (ll i = pos+1; i <= n; i++) {
		for (ll j = i - 1; j >= pos; j--) {
			if (pref[i] - pref[j] == r) {
				pos = i;
				res++;
				break;
			}
		}
	}
	return res;
}
void setans(ll r, ll x, ll y) {
	ans.clear();
	ans.pb({ y,x });
	for (ll i = x + 1; i <= n; i++) {
		for (ll j = i - 1; j >= x; j--) {
			if (pref[i] - pref[j] == r) {
				x = i;
				ans.pb({ j + 1,i });
				break;
			}
		}
	}
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
		pref[i] = A[i] + pref[i - 1];
	}
	ll k = 1;
	ans.pb({ 1,n });
	for (ll i = 1; i <= n; i++) {
		for (ll j = i - 1; j >= 0; j--) {
			if (S.count(pref[i] - pref[j]) == 1)continue;
			ll cof = findsum(pref[i] - pref[j], i);
			if (cof>k) {
				k = cof;
				setans(pref[i] - pref[j], i, j + 1);
			}
			S.insert(pref[i] - pref[j]);
		}
	}
	cout << k << endl;
	for (ll i = 0; i < k; i++) {
		cout << ans[i].first << ' ' << ans[i].sc << endl;
	}
	return 0;
}