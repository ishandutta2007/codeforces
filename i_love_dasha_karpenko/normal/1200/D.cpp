#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 2007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a,const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n, k,A[DIM][DIM],prefcol[DIM][DIM],prefro[DIM][DIM],pc[DIM][DIM],pr[DIM][DIM];
int main() {
	schnell;
	cin >> n >> k;
	forn(i, n) {
		forn(j, n) {
			char ch; cin >> ch;
			if (ch == 'B')A[i][j]++;
		}
	}
	for (ll j = 1; j <= n; j++) {
		for (ll i = 1; i <= n; i++)prefcol[j][i] = prefcol[j][i - 1] + A[i][j];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++)prefro[i][j] = prefro[i][j - 1] + A[i][j];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = k; j <= n; j++) {
			if (prefro[i][j] - prefro[i][j - k] == prefro[i][n])pr[i][j] = 1;
		}
	}
	ll res = 0;
	forn(i, n) {
		if (prefro[i][n] == 0)res++;
		if (prefcol[i][n] == 0)res++;
	}
	for (ll j = k; j <= n; j++) {
		for (ll i = 1; i <= n; i++) {
			pc[j][i] = pc[j][i - 1] + (prefro[i][j] - prefro[i][j - k] == prefro[i][n] && prefro[i][n] != 0);
		}
	}
	for (ll i = k; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			pr[i][j] = pr[i][j - 1] + (prefcol[j][i] - prefcol[j][i - k] == prefcol[j][n] && prefcol[j][n] != 0);
		}
	}
	ll r = 0;
	for (ll i = k; i <= n; i++) {
		for (ll j = k; j <= n; j++) {
			r = max(r, pr[i][j]-pr[i][j - k] + pc[j][i]-pc[j][i - k]);
		}
	}
	cout << res + r << endl;

	return 0;
}