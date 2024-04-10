#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 100007;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
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
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}
ll n, k,A[DIM],max;
int main() {
	schnell;
	cin >> n >> k;
	forn(i, n)cin >> A[i];
	sort(A + 1, A + 1 + n);
	ll mi = A[1], mx = A[n],cntmi = 0,cntmx = 0;
	forn(i, n) {
		if (A[i] != mi)break;
		cntmi++;
	}
	for (ll i = n; i >= 1; i--) {
		if (A[i] != mx)break;
		cntmx++;
	}
	while (1) {
		if (mi == mx)break;
		while (A[cntmi + 1] == mi)cntmi++;
		while (A[n-cntmx+1 - 1] == mx)cntmx++;
		ll r1 = A[cntmi + 1] - mi, r2 =  mx- A[n-cntmx+1 - 1];
		ll can1 = k / cntmi, can2 = k / cntmx;
		if (cntmi < cntmx) {
			ll g = min(can1, r1);
			k -= cntmi * g;
			mi += g;
		}
		else {
			ll g = min(can2, r2);
			k -= g*cntmx;
			mx -= g;
		}
		if (can1 == 0 && can2 == 0)break;
	}
	cout << mx - mi << endl;
	return 0;
}