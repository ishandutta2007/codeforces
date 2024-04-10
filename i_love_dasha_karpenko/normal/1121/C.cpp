#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long ll;
typedef long double ld;
#define DIM 1007
#define DIM2 DIM*150
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
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n, k,A[DIM],S[DIM],T[DIM2],V[DIM2];
int main() {
	schnell;
	cin >> n >> k;
	forn(i, n)cin >> A[i];
	ll t = 0;
	priority_queue<ll,vector<ll>,greater<ll> > Q;

	forn(i,min(n, k)) {
		Q.push(t + A[i]);
		S[i] = t;
	}
	ll h =min( n,k)+1,done = 0;
	while (!Q.empty()) {
		t = Q.top(); Q.pop();
		done++;
		ll r = round(ld(done) * 100 / n);
		if (h <= n) {
			Q.push(A[h] + t);
			S[h] = t;
			h++;
		}
		if (!Q.empty()) {
			ll qt = Q.top();
			for (ll i = t; i <qt; i++) {
				T[i] = r;
			}
		}
	}
	ll res = 0;
	forn(i, n) {
		for (ll j = 1; j <= A[i]; j++) {
			
			if (T[S[i] + j - 1] == j) {
				res++;
				break;
			}
		}
	}
	
	cout << res << endl;
	return 0;
}