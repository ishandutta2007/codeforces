#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
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
ll A[DIM], B[DIM];
int main()
{
	schnell;
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	forn(i, n) {
		cin >> A[i];
	}
	forn(i, m)cin >> B[i];
	ll res = 0;
	ll r = 1,k1 = k;
	if (k+1 > n) {
		cout << -1 << endl;
		return 0;
	}
	forn(i, k+1) {
		ll c = A[i];
		while (r<=m && c + ta > B[r])r++;
		
		if (r + k1 > m) {
			cout << -1 << endl;
			return 0;
		}
		res = max(res,B[r+k1] + tb);
		k1--;
	}
	cout << res << endl;
}
// 1 1 1 1 1 1 1 1
// 8 4
//   A      A