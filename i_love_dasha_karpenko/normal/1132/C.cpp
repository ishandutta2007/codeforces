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

ll n, q,C[DIM],mod[DIM],pref1[DIM],pref2[DIM];
pll A[DIM];
int main()
{
	schnell;
	cin >> n >> q;
	forn(i, q) {
		cin >> A[i].first >> A[i].sc;
		mod[A[i].fi - 1] ++;
		mod[A[i].sc]--;
	}
	ll res = 0;
	forn(i, n) {
		C[i] = C[i - 1] + mod[i - 1];
		pref1[i] = pref1[i - 1];
		pref2[i] = pref2[i - 1];
		if (C[i] > 0)res++;
		if (C[i] == 1)pref1[i]++;
		if (C[i] == 2)pref2[i]++;
	}
	ll mi = INF;
	forn(i, q) {
		for (ll j = i + 1; j <= q; j++) {
			ll lb = max(A[i].first, A[j].fi), rb = min(A[i].sc, A[j].sc);
			ll delta = pref1[A[i].sc] - pref1[A[i].first - 1] + pref1[A[j].sc] - pref1[A[j].first - 1];
			if (lb <= rb)delta += pref2[rb] - pref2[lb-1] - pref1[rb]+pref1[lb-1];
			mi = min(mi, delta);
		}
	}
	cout << res - mi << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;