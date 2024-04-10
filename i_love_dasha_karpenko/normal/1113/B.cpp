#include <bits/stdc++.h>

using namespace std;
#define DIM 50007
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
int main()
{
	schnell;
	cin >> n;
	ll mi = INF,sum = 0;
	forn(i, n) {
		cin >> A[i];
		mi = min(A[i], mi);
		sum += A[i];
	}
	ll res = 0;
	forn(i, n) {
		for (ll j = 1; j <= sqrt(A[i]); j++) {
			if (A[i] % j == 0) {
				ll su = A[i] / j + mi * j;
				if (res < A[i] + mi - su) {
					res = A[i] + mi - su;
				}
				if (A[i] % (A[i] / j) == 0) {
					ll jj = A[i] / j;
					ll su = A[i] / jj + mi * jj;
					if (res < A[i] + mi - su) {
						res = A[i] + mi - su;
					}
				}
			}
		}
	}
	cout << sum - res << endl;
}