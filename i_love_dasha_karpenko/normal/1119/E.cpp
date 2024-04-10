#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
#define DIM2 10007
#define MODULO 10000000000 
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
ll n;
int main() {
	schnell;
	cin >> n;
	ll res = 0,r1 = 0;
	forn(i, n) {
		ll x = 0;
		cin >> x;
		ll cof = min(x / 2, r1);
		x -= cof * 2;
		res += cof;
		r1 -= cof;
		cof = x / 3;
		x %= 3;
		res += cof;
		r1 += x;
	}
	cout << res << endl;
	
	return 0;
}