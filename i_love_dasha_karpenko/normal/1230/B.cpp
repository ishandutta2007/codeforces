#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 107
#define MODULO 998244353 
const ll MAXN = ll(10E8);
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
ll n, k;
int main() {
	schnell;
	cin >> n >> k;
	if (n == 1 ) {
		char ch; cin >> ch;
		if (k > 0) {
			cout << 0 << endl;
		}
		else cout << ch << endl;
		return 0;
	}
	forn(i, n) {
		char ch; cin >> ch;
		ll x; x = ch - '0';
		if (k>0 && i == 1 && x != 1) {
			x = 1;
			k--;
		}
		else if (i != 1 && k > 0 && x != 0) {
			x = 0;
			k--;
		}
		cout << x;
	}
	cout << endl;
	return 0;
}