#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
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

ll q, n,h,A[DIM];
int main() {
	schnell;
	cin >> q;
	forn(query, q) {
		cin >> h >> n;
		forn(i, n) {
			cin >> A[i];
		}
		ll res = 0,lastpos = h;
		A[n + 1] = 0;
		forn(i, n) {
			if (lastpos == A[i])continue;
			if (A[i] - A[i + 1] >= 2) {
				res++;
				lastpos = A[i];
			}
			else {
				lastpos = A[i + 1];
			}
		}
		cout << res << endl;
	}
	return 0;
}