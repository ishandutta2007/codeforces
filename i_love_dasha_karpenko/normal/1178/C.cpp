#include <bits/stdc++.h>

using namespace std;
#define DIM 5007
#define DIM2 200007
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

string s;
ll w,h;
ll p(ll num,ll x) {
	
	while (x > 0) {
		x--;
		num *= 2;
		num %= MODULO;
	}
	return num;
}
int main()
{
	schnell;
	cin >> w >> h;
	ll res = p(1,w + 1);
	res = p(res, h - 1);
	res %= MODULO;
	cout << res << endl;
}
// (a+k)%(b+k)
// a-b*x;