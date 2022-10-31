#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 1007
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
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n, m, A[DIM], B[DIM], V[DIM * 2];
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
		V[A[i]] = 1;
	}
	cin >> m;
	forn(i, m) {
		cin >> B[i];
		V[B[i]] = 1;
	}
	forn(i, n) {
		forn(j, m) {
			if (V[A[i] + B[j]] == 0) {
				cout << A[i] << ' ' << B[j] << endl;
				return 0;
			}
		}
	}
	return 0;
}