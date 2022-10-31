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
ll n, q;
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
	cin >> q;
	forn(h, q) {
		ll a; cin >> a;
		ll lo = log2(a);
		lo++;
		if (po(lo) - 1 != a) { cout << po(lo) - 1 << endl;
		continue;
		}
		ll flag = 0;
		for (ll i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				cout << a / i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << 1 << endl;
		}
	}
	return 0;
}