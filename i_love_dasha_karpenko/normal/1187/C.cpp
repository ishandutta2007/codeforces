#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
#define DIM2 100007
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
struct node {
	ll m, l, r;
};
ll n, m, C[DIM], P[DIM];
vector<pll> A;

int main()
{
	schnell;
	cin >> n >> m;
	forn(i, n)C[i] = i;
	forn(i, m) {
		ll t, l, r;
		cin >> t >> l >> r;

		if (t == 1) {
			for (ll i = l + 1; i <= r; i++) {
				P[i] = 1;
			}
		}
		else {
			
			A.pb({ l, r });
		}
	}
	fore(2,i, n) {
		while (P[i] == 1)i++;
		ll l = i-1;
		while (i<=n && P[i] == 0)i++;
		if (P[i-1]==0){
			ll r = i - 1;
			for (ll j = l; j <= r; j++) {
				C[j] = r - j + l;
			}
		}

	}
	for (pll to : A) {
		ll l = to.first, r = to.sc, flag = 0;
		for (ll i = l; i <= r - 1; i++) {
			if (C[i] > C[i + 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	forn(i, n)cout << C[i] << ' ';
	cout << endl;
	return 0;
}