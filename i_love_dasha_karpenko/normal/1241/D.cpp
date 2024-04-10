#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long  ll;
typedef long double ld;
#define DIM 300007
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

ll q, n, A[DIM],L[DIM],R[DIM];
set<ll>elems;
int main() {
	schnell;
	cin >> q;
	forn(query, q) {
		cin >> n;
		elems.clear();
		forn(i, n) {
			cin >> A[i];
			R[A[i]] = i;
			if (elems.count(A[i]) == 0)L[A[i]] = i;
			elems.insert(A[i]);
		}
		ll bound = 0,cres = 0,res = 0;
		for (ll to : elems) {
			if (L[to] > bound) {
				cres++;
				bound = R[to];
			}
			else {
				res = max(res, cres);
				cres = 1;
				bound = R[to];
			}
		}
		res = max(res, cres);
		cout << elems.size()-res << endl;
	}
	return 0;
}