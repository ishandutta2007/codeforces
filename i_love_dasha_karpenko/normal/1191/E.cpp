#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
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

ll n, k, A[DIM],pref[2][DIM],suf[2][DIM];
int main()
{
	schnell;
	cin >> n >> k;
	forn(i, n) {
		char ch; cin >> ch;
		A[i] = ch - '0';
	}
	forn(i, n) {
		pref[A[i]][i] = pref[A[i]][i - 1] + 1;
	}
	for (ll i = n; i >= 1; i--) {
		suf[A[i]][i] = suf[A[i]][i + 1] + 1;
	}
	forn(i, n - k+1) {
		ll p1 = i, p2 = i + k - 1;
		if (pref[0][p1 - 1] + k + suf[0][p2 + 1] == n) {
			cout << "tokitsukaze" << endl;
			return 0;
		}
		if (pref[1][p1 - 1] + k + suf[1][p2 + 1] == n) {
			cout << "tokitsukaze" << endl;
			return 0;
		}
	}
	ll res = 0;
	forn(i, n - k + 1) {
		ll p1 = i, p2 = i + k - 1,cf = 0,rr = 0;
		fore(0, y, 1) {
			if (pref[y][p1 - 1] == p1 - 1) {
				if (suf[y][p2 + 1] + k >= n - p2 || suf[y][p2 + k] >= n - p2 - k + 1)cf = 1;
			}
			if (suf[y][p2 + 1] == n - p2) {
				if (pref[y][p1 - 1] + k >= p1 - 1 || pref[y][p1 - k] >= p1 - k)cf = 1;
			}
			rr+=cf;
		}
		if (rr !=2) {
			cout << "once again" << endl;
			return 0;
		}
	}
	
	cout << "quailty" << endl;
	return 0;
}