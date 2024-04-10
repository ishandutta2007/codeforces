#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
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
ll n,A[DIM];
int main()
{
	schnell;
	cin >> n;
	ll pos, mx = 0;
	forn(i, n) {
		cin >> A[i];
		if (mx < A[i]) {
			mx = A[i];
			pos = i;
		}
	}
	ll l = pos - 1, r = pos + 1,last = A[pos];
	while (l >= 1 || r <= n) {
		if (l >= 1 && r <= n) {
			if (last < max(A[l], A[r])) {
				cout << "NO" << endl;
				return 0;
			}
			if (A[l] > A[r]) {
				last = A[l];
				l--;
			}
			else {
				last = A[r];
				r++;
			}
		}
		else if (l >= 1) {
			if (last < A[l]) {
				cout << "NO" << endl;
				return 0;
			}
			else {
				last = A[l];
				l--;
			}
		}
		else {
			if (last < A[r]) {
				cout << "NO" << endl;
				return 0;
			}
			else {
				last = A[r];
				r++;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;