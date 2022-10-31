#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 2007
#define DIM2 DIM*150
#define MODULO 998244353 
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const ll INF = 10E16;
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
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n;
ll A[DIM];
map<ll, ll> M;
set<ll> S;
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
		M[A[i]]++;
		if (M[A[i]] > 1)S.insert(A[i]);
	}
	ll res = INF;
	forn(i, n) {
		map<ll, ll> cm;
		ll r = 0,l = 0;
		for (ll j = i; j <= n; j++) {
			if (r == S.size())break;
			cm[A[j]]++;
			if (cm[A[j]] == M[A[j]]-1) {
				r++;
			}
			l++;
		}
		if (r==S.size())
		res = min(res, l);
	}
	cout << res << endl;
	return 0;
}