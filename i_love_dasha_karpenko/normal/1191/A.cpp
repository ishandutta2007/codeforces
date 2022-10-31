#include <bits/stdc++.h>

using namespace std;
#define DIM 101
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

ll x;
int main()
{
	schnell;
	cin >> x;
	ll cof = x % 4;
	if (cof == 0) {
		cout << 1 << ' ' << 'A' << endl;
		return 0;
	}
	if (cof == 1) {
		cout << 0 << ' ' << 'A' << endl;

	}
	if (cof == 2) {
		cout << "1 B\n";
	}
	if (cof == 3) {
		cout << "2 A\n" << endl;

	}
	return 0;
}