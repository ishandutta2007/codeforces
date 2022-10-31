#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007

typedef long long ll;
const ll MASK(1 << 10);
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef ll msk[MASK+7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll n, q,turns;
arr A;
pll H[DIM],T[DIM];
deque<ll> Q;
int main()
{
	schnell;
	ll mx = 0;
	cin >> n >> q;
	forn(i, n) {
		ll x;
		cin >> x;
		Q.pb(x);
		mx = max(mx, x);
	}
	ll u = 0;
	while (Q.front()!=mx) {
		ll x = Q.front(); Q.pop_front();
		ll y = Q.front(); Q.pop_front();
		if (x > y) {
			Q.push_front(x);
			Q.pb(y);
		}
		else {
			Q.push_front(y);
			Q.pb(x);
		}
		
		//if (Q.front() == mx)break;
		++u;
		H[u] = { x,y };
	}
	//u++;
	forn(i, n) {
		ll x = Q.front(); Q.pop_front();
		ll y = Q.front(); Q.pop_front();
		if (x > y) {
			Q.push_front(x);
			Q.pb(y);
		}
		else {
			Q.push_front(y);
			Q.pb(x);
		}
		
		T[i] = { x,y };
	}
	forn(e, q) {
		ll x; cin >> x;
		if (x <= u) {
			cout << H[x].first << ' ' << H[x].sc << endl;
		}
		else {
			ll cof = x - u;
			cof %= (n - 1);
			if (cof == 0)cof = n - 1;
			cout << T[cof].first << ' ' << T[cof].sc << endl;
		}
	}
}