#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
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

int main() {
	schnell;
	ll t;
	cin >> t;
	forn(e, t) {
		ll n, a, b;
		cin >>a >> b>>n;
		if (n == 0) {
			cout << a << endl;
			continue;
		}
		else if (n == 1) {
			cout << b << endl;
			continue;
		}
		n -= 1;
		if (n % 3 == 1) {
			cout << (a ^ b) << endl;
		}
		else if (n % 3 == 2) {
			cout << a << endl;
		}
		else {
			cout << b << endl;
		}
	}

	

	return 0;
}