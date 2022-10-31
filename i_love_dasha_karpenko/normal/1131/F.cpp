#include <bits/stdc++.h>

using namespace std;
#define DIM 150007
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

typedef   int ll;
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
ll n, P[DIM],last[DIM],nx[DIM];
ll F(ll x) {
	if (x == P[x])return x;
	P[x] = F(P[x]);
	return P[x];
}

void unite(ll x, ll y) {
	x = F(x);
	y = F(y);
	
	if (rand() % 2 == 0) {
		
		P[y] = x;
		nx[last[x]] = y;
		
		last[x] = last[y];
	}
	else {
		P[x] = y;
		nx[last[y]] = x;
		
		last[y] = last[x];
		
	}
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		P[i] = i;
		last[i] = i;
	}
	forn(i, n-1) {
		ll x, y;
		cin >> x >> y;
		unite(x, y);
	}
	ll start;
	forn(i, n) {
		if (P[i] == i) {
			start = i;
			break;
		}
	}
	forn(i, n) {
		cout << start << ' ';
		start = nx[start];
	}
	cout << endl;
}
// 1 1 1 1 1 1 1 1
// 8 4
//   A      A