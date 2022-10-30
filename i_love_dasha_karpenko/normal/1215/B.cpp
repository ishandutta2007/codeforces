#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
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
ll n;
int main() {
	schnell;
	cin >> n;
	ll r1 = 0, r2 = 1, r = 0,res1 = 0,res2 = 0;
	forn(i, n) {
		ll x;
		cin >> x;
		r += (x < 0);
		if (r % 2 == 0) {
			res1 += r1; res2 += r2;
		}
		else {
			res1 += r2;
			res2 += r1;
		}
		if (r % 2 == 0)r2++;
		else r1++;
	}
	cout << res1 << ' ' << res2 << endl;
	
	return 0;
}