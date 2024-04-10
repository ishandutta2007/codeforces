#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
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

typedef  short int ll;
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
ll n, m, flag = 0, V[DIM], V1[DIM],val[DIM],val1[DIM];
vector<pll> A[DIM], B[DIM],  T;

void topsort(ll x, ll par, ll dim,ll v) {
	if (dim == 1) {
		V[x] = 1;
		val[x] = v;
		for (pll to : A[x]) {
			if (V1[to.fi] == 1 && val1[to.first]!=v+to.sc) {
				flag = 1;
				return;
			}
			if (V1[to.fi] == 0)topsort(to.first, x, 2,v+to.sc);
		}
		T.pb({ x,1 });
		V[x] = 2;
	}
	if (dim == 2) {
		val1[x] = v;
		V1[x] = 1;
		for (pll to : B[x]) {
			if (V[to.fi] == 1 && val[to.first]!=v+to.sc) {
				flag = 1;
				return;
			}
			if (V[to.fi] == 0)topsort(to.first, x, 1,v+to.sc);
		}
		T.pb({ x,2 });
		V1[x] = 2;
	}
}
void findans(ll x, ll val, ll par, ll dim) {
	if (dim == 1) {
		if (V[x] >= val)return;
		V[x] = val;
		for (pll to : A[x]) {
			
			findans(to.first, val + to.sc, x, 3 - dim);

		}
	}
	if (dim == 2) {
		if (V1[x] >= val)return;
		V1[x] = val;
		for (pll to : B[x]) {
			if (to.fi == par)continue;
			findans(to.first, val + to.sc, x, 3 - dim);
		}
	}
}
int main()
{
	schnell;
	cin >> n >> m;
	forn(i, n) {
		forn(j, m) {
			char ch; cin >> ch;
			if (ch == '<') {
				A[i].pb({ j,1 });
			}
			else if (ch == '>') {
				B[j].pb({ i,1 });
			}
			else {
				A[i].pb({ j,0 });
				B[j].pb({ i,0 });
				
			}
		}
	}
	forn(i, n) {
		if (V[i]==0)
			topsort(i, 0, 1,1);
	}
	forn(i, m) {
		if (V1[i] == 0)
			topsort(i, 0, 2,1);
	}
	if (flag == 1) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	memset(V, 0, sizeof(V));
	memset(V1, 0, sizeof(V1));
	for (ll i = T.size() - 1; i >= 0; i--) {
		if ((T[i].sc==1 && V[T[i].first]==0) || (T[i].sc==2 && V1[T[i].first]==0))
			findans(T[i].first, 1, 0, T[i].sc);
	}
	forn(i, n) {
		cout << V[i] << ' ';
	}
	cout << endl;
	forn(i, m) {
		cout << V1[i] << ' ';
	}
	cout << endl;
	return 0;
}
// 1 1 1 1 1 1 1 1
// 8 4
//   A      A