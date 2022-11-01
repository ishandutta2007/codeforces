#include <bits/stdc++.h>

using namespace std;
#define DIM 5007
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

ll n, k,A[DIM],D[DIM],suf[DIM][DIM];

int main()
{
	schnell;
	cin >> n >> k;
	forn(i, n)cin >> A[i];
	sort(A + 1, A + 1 + n);
	forn(i, n) {
		auto it = upper_bound(A + 1, A + 1 + n, A[i] + 5);
		ll k = it - A;
		k--;
		while (A[k] - A[i] > 5)k--;
		D[i] = k;
	}
	for (ll i = n; i >= 1; i--) {
		forn(j, k) {
			suf[j][i] = max(max(suf[j][i+1],suf[j - 1][i + 1] + 1) , suf[j - 1][D[i] + 1] + D[i] - i + 1);
		}
	}
	cout << suf[k][1] << endl;
}