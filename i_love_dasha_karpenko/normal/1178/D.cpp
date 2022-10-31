#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
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

ll n, res = 0,simp[DIM*DIM];
vector<ll> V,A[DIM];
pll num[DIM];
set<pll> S;
int main()
{
	schnell;
	cin >> n;
	simp[1] = 1;
	simp[0] = 1;
	for (ll i = 2; i <= n*n; i++) {
		if (simp[i] == 0) {
			for (ll j = i * i; j <= n*n; j += i)simp[j] = 1;
			V.pb(i);
		}
	}
	forn(i, n)num[i].sc = i;
	ll s = 0;
	while (simp[res] != 0 || s!=n) {
		sort(num + 1, num + 1 + n);
		ll start = num[1].first;
		auto it = upper_bound(V.begin(), V.end(), start);
		ll pos = it - V.begin();
		if (pos >= V.size()) {
			cout << -1 << endl;
			return 0;
		}
		ll si = V[pos];
		ll delta = si - start;
		ll top = num[1].sc;
		if (simp[start] == 1)s++;
		
		ll cn = 0;
		for (ll i = 2; i <=n && cn<delta; i++) {
			if (S.count({ min(num[i].sc, top), max(num[i].sc, top) }) != 0)continue;
			A[top].pb(num[i].sc);
			num[i].fi++;
			num[1].fi++;
			cn++;
			S.insert({ min(num[i].sc, top), max(num[i].sc, top) });
			res++;
			if (!(simp[num[i].fi] == simp[num[i].first - 1])) {
				if (simp[num[i].fi] == 0)s++;
				if (simp[num[i].fi - 1] == 0)s--;
			}
		}
		if (cn < delta) {
			cout << -1 << endl;
			return 0;
		}
	}
	if (s != n || simp[res] != 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << res << endl;
	forn(i, n) {
		for (ll to : A[i]) {
			cout << i << ' ' << to << endl;
		}
	}
	return 0;
}
// (a+k)%(b+k)
// a-b*x;