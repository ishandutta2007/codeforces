#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
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
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
//typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n, m,vis[DIM];
vector<ll> A[DIM2];
vector<ll> V[DIM];
int Check(ll x) {
	memset(vis, 0, sizeof(vis));
	ll res = 0;
	for(ll to:A[x]) {
		for (ll f : V[to]) {
			if (vis[f] == 0) {
				res++;
				vis[f] = 1;
			}
		}
	}	
	if (res != m)return 1;
	return 0;
}
int main()
{
	schnell;	
	cin >> m >> n;
	forn(i, m) {
		ll x, mask = 0;
		cin >> x;
		A[i].resize(x + 5);
		forn(j, x) {
			ll y;
			cin >> y;
			A[i].pb(y);
			V[y].pb(i);
		}
	}
	forn(i, m) {
		if (Check(i)) {
			cout << "impossible" << endl;
			return 0;
		}
	}
	cout << "possible" << endl;
}
// x2+y2 == (x+y)2-2xy
// (x+y)( (x+y)2-2xy
// (x+y)3 -