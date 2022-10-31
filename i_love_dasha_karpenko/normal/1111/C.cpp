#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
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

typedef  unsigned long long ll;
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

ll n, k, a, b, A[DIM];
map<pll,ll> M;
ll dp(ll l, ll r) {
	if (M.count({ l,r }) == 1)return M[{l, r}];
	auto it = lower_bound(A + 1, A + 1 + k, l);
	ll k1 = it - A;
	auto it1 = upper_bound(A + 1, A + 1 + k, r);
	ll k2 = it1 - A;
	ll res = k2 - k1;
	if (res == 0) {
		res = a;
		M[{l, r}] = a;
		return a;
	}
	else {
		res = (r - l + 1) * res * b;
	}
	if (l!=r)
	res = min(res, dp(l, (r + l) / 2) + dp((l + r) / 2 + 1, r));
	M[{l, r}] = res;
	return res;
}
int main()
{
	schnell;
	cin >> n >> k >> a >> b;
	n = pow(2, n);
	forn(i, k) {
		cin >> A[i];
	}
	sort(A + 1, A + 1 + k);
	cout << dp(1, n) << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;