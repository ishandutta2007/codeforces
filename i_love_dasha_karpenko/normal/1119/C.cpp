#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 507
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n, m,A[DIM][DIM],B[DIM][DIM];
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n)
		forn(j, m)
		cin >> A[i][j];
	forn(i, n) 
		forn(j, m)
		cin >> B[i][j];
	for (ll j = 1; j < m; j++) {
		for (ll i = 2; i <= n; i++) {
			if (A[i][j] != B[i][j]) {
				A[i][j] ^= 1;
				A[i][j + 1] ^= 1;
				A[1][j] ^= 1;
				A[1][j + 1] ^= 1;
			}
		}
	}
	forn(i, n) {
		forn(j, m) {
			if (A[i][j] != B[i][j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}