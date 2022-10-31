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

ll n;
pair<ll, char> A[DIM];
set<char> S[10];
int main()
{
	schnell;
	n = 3;
	forn(i, n) {
		cin >> A[i].first >> A[i].sc;
		S[A[i].fi].insert(A[i].sc);

	}
	sort(A + 1, A + 1 + n);

	ll res = 2;
	forn(i, n) {
		if (n - i >= 2 && A[i].fi == A[i + 1].fi && A[i].fi == A[i + 2].first && A[i].sc == A[i + 1].sc && A[i].sc == A[i + 2].sc) {
			res = 0;
		}
		if (n - i >= 1 && A[i].fi == A[i + 1].fi && A[i].sc == A[i + 1].sc) {
			res = min(res, ll(1));
		}
		if (n - i >= 2 && A[i].fi == A[i + 2].fi && A[i].sc == A[i + 2].sc) {
			res = min(res, ll(1));
		}
	}
	forn(i, 9) {
		char r = 's';
		if (9 - i >= 2 && S[i].count(r) == 1 && S[i + 1].count(r) == 1 && S[i + 2].count(r) == 1) {
			res = 0;
		}
		if (9 - i >= 1 && S[i].count(r) == 1 && S[i + 1].count(r) == 1) {
			res = min(res, ll(1));
		}
		if (9 - i >= 2 && S[i].count(r) == 1 && S[i + 2].count(r) == 1) {
			res = min(res, ll(1));
		}
		r = 'm';
		if (9 - i >= 2 && S[i].count(r) == 1 && S[i + 1].count(r) == 1 && S[i + 2].count(r) == 1) {
			res = 0;
		}
		if (9 - i >= 1 && S[i].count(r) == 1 && S[i + 1].count(r) == 1) {
			res = min(res, ll(1));
		}
		if (9 - i >= 2 && S[i].count(r) == 1 && S[i + 2].count(r) == 1) {
			res = min(res, ll(1));
		}
		r = 'p';
		if (9 - i >= 2 && S[i].count(r) == 1 && S[i + 1].count(r) == 1 && S[i + 2].count(r) == 1) {
			res = 0;
		}
		if (9 - i >= 1 && S[i].count(r) == 1 && S[i + 1].count(r) == 1) {
			res = min(res, ll(1));
		}
		if (9 - i >= 2 && S[i].count(r) == 1 && S[i + 2].count(r) == 1) {
			res = min(res, ll(1));
		}
	}
	cout << res << endl;
	return 0;
}