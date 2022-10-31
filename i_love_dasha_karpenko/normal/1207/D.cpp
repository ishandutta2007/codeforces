#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
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
ll n,F[DIM],all = 1;
pp A[DIM];
ll fa(ll x) {
	return F[x];
}
bool mc(pp x, pp y) {
	return x.sc < y.sc;
}
int main() {
	schnell;
	cin >> n;
	ll val = 1;
	for (ll i = 1; i <= n; i++) {
		val = (val * i) % MODULO;
		F[i] = val;
	}
	F[1] = 1;
	forn(i, n)cin >> A[i].fi >> A[i].sc;
	ll res = fa(n);
	sort(A + 1, A + 1 + n);
	ll lres = 1, m1 = 1;
	for (ll i = 1; i <= n; i++) {
		if (A[i].fi == A[i - 1].fi)lres++;
		else {
			m1 = (m1 * fa(lres)) % MODULO;
			lres = 1;
		}
	}
	m1 = (m1 * fa(lres)) % MODULO;
	ll flag = 0, su = 1, lres1 = 1;
	forn(i, n) {
		if (A[i].sc < A[i - 1].sc) {
			flag = 1;
			break;
		}
		if (A[i] == A[i - 1])lres1++;
		else {
			su = (su * fa(lres1))%MODULO;
			lres1 = 1;
		}
	}
	su = (su * fa(lres1)) % MODULO;
	if (flag==0)
	res = (res + su) % MODULO;
	res -= m1;
	if (res < 0)res += MODULO;
	sort(A + 1, A + 1 + n, mc);
	lres = 1;
	ll m2 = 1;
	forn(i, n) {
		if (A[i].sc == A[i - 1].sc) {
			lres++;
		}
		else {
			m2 = (m2 * fa(lres)) % MODULO;
			lres = 1;
		}
	}
	m2 = (m2 * fa(lres)) % MODULO;
	res -= m2;
	if (res < 0)res += MODULO;
	cout << res << endl;
	return 0;
}