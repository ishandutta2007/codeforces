#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 100007
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
ll b, k,A[DIM];
int main() {
	schnell;
	cin >> b >> k;
	ll res1 = 0, res2 = 0;
	forn(i, k) {
		ll x; cin >> A[i];
		x = A[i];
		if (x % 2 == 0)res1++;
		else res2++;
	}
	if (b % 2 == 0) {
		if (A[k] % 2 != 0) {
			cout << "odd" << endl;
		}
		else {
			cout << "even" << endl;
		}
	}
	else {
		if (res2 % 2 == 0) {
			cout << "even" << endl;
		}
		else {
			cout << "odd" << endl;
		}
	}
	return 0;
}