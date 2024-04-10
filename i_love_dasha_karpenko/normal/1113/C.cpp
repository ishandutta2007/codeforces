#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define DIM2 100007
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
ll n,A[DIM];
map<ll,ll> pref,pref1;
int main()
{
	schnell;
	cin >> n;
	ll ba = 0;
	forn(i, n) {
		cin >> A[i];
	}
	ll cur = 0;
	pref[0] = 1;
	//pref1[0] = 1;
	ll res = 0;
	forn(i, n) {
		if (i % 2 == 1) {
			cur ^= A[i];

			res += pref1[cur];
			pref1[cur]++;
		}
		else {
			cur ^= A[i];
			res += pref[cur];
			pref[cur]++;
		}
	}
	cout << res << endl;
}