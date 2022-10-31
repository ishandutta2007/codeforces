#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
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

ll r;

int main()
{
	schnell;
	cin >> r;
	r--;
	ll sq = sqrt(r);
	for (ll i = 1; i <= sq; i++) {
		if (r % i == 0) {
			ll cf = r / i;
			cf -= i+1;
			if (cf > 0 && cf % 2 == 0) {
				cout << i << ' ' << cf / 2 << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}