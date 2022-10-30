#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long ll;
typedef long double ld;
#define DIM 21
#define MODULO 998244353 
#define MAXN 1000000
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
ll n, m,pen;
int main() {
	schnell;
	cin >> n >> m;
	ll h = 0;
	ll k1, k2;
	cin >> k1 >> k2;
	
	cin >> pen;
	cout << max(ll(0), min(pen - (k1 - 1) * n - (k2 - 1) * m, n + m)) << ' ';
	if (k1 < k2) { swap(k1, k2); swap(n, m); }
	ll r2 = min(pen / k2, m);
	pen -= r2 * k2;
	ll r1 = min(pen / k1, n);
	cout << r1 + r2 << endl;
	
	return 0;
}