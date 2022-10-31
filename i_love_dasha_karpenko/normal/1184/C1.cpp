#include <bits/stdc++.h>

using namespace std;
#define DIM 60
#define DIM2 57
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
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef pair<pll, pll> pllll;
//typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n, V[DIM];
pll A[DIM];
int main()
{
	schnell;
	cin >> n;
	n *= 4;
	n++;
	ll lbound = INF, rbound = -1, top = -1, bot = INF;
	forn(i, n) {
		cin >> A[i].fi >> A[i].sc;
		lbound = min(lbound, A[i].fi);
		rbound = max(rbound, A[i].fi);
		top = max(top, A[i].sc);
		bot = min(bot, A[i].sc);
	}
	ll vert = top - bot, hor = rbound - lbound;
	if (vert != hor) {
		if (vert > hor) {
			ll res1 = 0, res2 = 0;
			forn(i, n) {
				if (A[i].sc == top)res1++;
				if (A[i].sc == bot)res2++;
			}
			if (res1 > res2) {
				forn(i, n) {
					if (A[i].sc == bot) {
						cout << A[i].first << ' ' << A[i].sc << endl;
						return 0;
					}
				}
			}
			else {
				forn(i, n) {
					if (A[i].sc == top) {
						cout << A[i].first << ' ' << A[i].sc << endl;
						return 0;
					}
				}
			}
		}
		else {
			ll res1 = 0, res2 = 0;
			forn(i, n) {
				if (A[i].fi == lbound)res1++;
				if (A[i].fi == rbound)res2++;
			}
			if (res1 > res2) {
				forn(i, n) {
					if (A[i].fi == rbound) {
						cout << A[i].first << ' ' << A[i].sc << endl;
						return 0;
					}
				}
			}
			else {
				forn(i, n) {
					if (A[i].fi == lbound) {
						cout << A[i].first << ' ' << A[i].sc << endl;
						return 0;
					}
				}
			}
		}
	}
	forn(i, n) {
		if (!(A[i].first >= lbound && A[i].first <= rbound) || !(A[i].sc <= top && A[i].sc >= bot) || (A[i].first != lbound && A[i].first != rbound && A[i].sc != top && A[i].sc != bot)) {
			cout << A[i].first << ' ' << A[i].sc << endl;
			return 0;
		}
	}
}