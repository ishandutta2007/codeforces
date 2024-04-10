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
ll n, A[DIM][DIM];
set<ll> S;
int main() {
	schnell;
	
	cin >> n;
	ll r = 0;
	for (ll i = 1; i <= n; i += 4) {
		for (ll j = 1; j <= n; j+=4) {
			for (ll ii = i; ii < i + 4; ii++) {
				for (ll jj = j; jj < j + 4; jj++) {
					A[ii][jj] = r;
					r++;
				}
			}
		}
	}
	forn(i, n) {
		
		forn(j, n) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}