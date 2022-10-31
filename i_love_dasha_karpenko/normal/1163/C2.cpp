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

ll n;
pll A[DIM];
map<pll, ll> D;
set<pllll> dot;
ll __gcd(ll x, ll y) {
	while (x != 0 && y != 0) {
		if (abs(x) > abs(y))x %= y;
		else y %= x;
	}
	if (x + y == 0)return 1;
	return x + y;
}
pllll goto0(pll a, pll b) {
	if (a.first > b.first)swap(a, b);
	if (a.first == b.first && a.second > b.second)swap(a, b);
	ll gcd = __gcd(abs(b.first - a.first), abs(b.second - a.second));
	pll vec = { (b.first - a.first) / gcd,(b.second - a.second) / gcd };
	pll dot;
	if (vec.sc == 0) {
		dot = { 0,a.sc };
	}
	else {
		ll cof = a.sc / vec.sc;
		if (a.sc < 0 && a.sc % vec.sc != 0) {
			if (vec.sc < 0)cof++;
			else cof--;
		}
		dot = { a.first - cof * vec.first,a.sc - cof * vec.sc };
	}
	pllll res = { vec,dot };
	return res;
}
int main()
{
	schnell;
	cin >> n;

	forn(i, n) {
		cin >> A[i].fi >> A[i].sc;
	}
	ll res = 0, same = 0;
	forn(i, n) {
		fore(i + 1, j, n) {
			pllll k = goto0(A[i], A[j]);
			if (dot.count(k) == 0) {
				res++;
				dot.insert(k);
				D[k.fi]++;
			}
		}
	}
	ll ans = 0;
	for (auto it : D) {
		ll num = it.second;
		ans += (res - num) * num;
	}
	cout << ans / 2 << endl;
}