#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353  
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
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
ll n, A[DIM];
bool mc(ll x, ll y) {
	return x > y;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
	}
	sort(A + 1, A + 1 + n,mc);
	ll r = 0;
	for (ll i = n; i > 2; i--) {
		ll r = A[1] - A[2];
		if (A[i] >= r) {
			A[1] = min(A[1], A[2]);
			A[2] = A[1];
			A[i] -= r;
			ll c = A[i] / 2;
			if (A[1] == 0) {

			}
			else {
				A[1] -= c;
				A[2] -= A[i] - c;
			}
		}
		else {
			if (A[1] > A[2])A[1] -= A[i];
			else A[2] -= A[i];
		}
	}

	if (r==0 && A[1] == A[2]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}