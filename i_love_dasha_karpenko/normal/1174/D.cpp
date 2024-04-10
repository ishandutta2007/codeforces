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
typedef ll msk[MASK];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
#define a first
#define b second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll n, x;
arr A,pref;
vector<ll> V;
int main()
{
	schnell;
	//cout << (3^6) << endl;
	cin >> n >> x;
	pref[0] = 1;
	V.pb(0);
	for (int i = 1;i<(1<<n); i++) {
		if (pref[i ^ x]==1)continue;
		pref[i] = 1;
		V.pb(i);
	}
	cout << V.size() - 1 << endl;
	forn(i, V.size() - 1) {
		cout << (V[i] ^ V[i - 1]) << ' ';
	}
	cout << endl;
	return 0;
}