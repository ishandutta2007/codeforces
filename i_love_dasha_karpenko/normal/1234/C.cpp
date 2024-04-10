#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = 1048576;
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
ll n,q,A[2][DIM];
int main() {
	schnell;
	cin >> q;
	forn(reer, q) {
		cin >> n;
		for (ll k = 0; k < 2; k++) {
			forn(i, n) {
				char x;
				cin >> x;
				A[k][i] = x-'0';
			}
		}
		ll a = 1, b = 0;
		forn(i, n) {
			if (A[0][i] > 2 && A[1][i] > 2) {
				ll a1 = a, b1 = b;
				a = b1; b = a1;
			}
			else {
				if (A[0][i] > 2) {
					a = 0;
				}
				if (A[1][i] > 2)b = 0;
			}
		}
		if (b == 1)cout << "YES" << endl;
		else cout << "NO\n";
	}
	
	return 0;
}