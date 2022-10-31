#include <bits/stdc++.h>

using namespace std;
#define DIM 25
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
ll n,A[DIM2],L[DIM],ans[DIM];
ll cn(ll x) {
	ll res = 0;
	while (x > 0) {
		x /= 10;
		res++;
	}
	return res;
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
		L[cn(A[i])]++;
	}
	forn(i, n) {
		ll x = A[i],l = 0;
		while (x > 0) {
			x /= 10;
			l++;
		}
		forn(j, 10) {
			x = A[i];
			if (j < l) {
				//L[j] *= 2;
				ll pos = 1;
				while (pos <= j * 2) {
					ans[pos] += x % 10*L[j]%MODULO;
					ans[pos + 1] += x % 10 * L[j]%MODULO;
					pos += 2;
					x /= 10;
				}
				while (pos <= j * 2 + (l - j)) {
					ans[pos] += x % 10 * L[j]*2%MODULO;
					pos++;
					x /= 10;
				}
				//L[j] /= 2;
			}
			else {
				ll pos = 1;
				while (x > 0) {
					ans[pos] += x % 10 * L[j]%MODULO;
					ans[pos + 1] += x % 10 * L[j]%MODULO;
					x /= 10;
					pos += 2;
				}
			}
		}
	}
	ll res = 0;
	forn(i, DIM - 2) {
		forn(j, i - 1) {
			ans[i] *= 10;
			ans[i] %= MODULO;
		}
		res += ans[i];
		res %= MODULO;
	}
	cout << res << endl;
}