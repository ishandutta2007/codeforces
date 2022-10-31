#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 7
#define DIM2 10007
#define MODULO 1000000007  
#define MAXN 1000000
#define BigNumSize 250
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.000000001;
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
ll n, m, q;
ll __gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	while (y > 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}
int main() {

	schnell;
	cin >> n >> m >> q;
	ll g = __gcd(n, m);
	ll g1 = n / g;
	ll g2 = m / g;
	forn(e, q) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		ld pos1, pos2;
		if (x == 1) {
			pos1 = y / g1;
			if (y % g1)pos1++;
		}
		else {
			pos1 = y / g2;
			if (y % g2)pos1++;
		}
		if (a == 1) {
			pos2 = b/g1;
			if (b % g1)pos2++;
		}
		else {
			pos2 =  b/g2;
			if (b % g2)pos2++;
		}
		if (pos1 != pos2) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}