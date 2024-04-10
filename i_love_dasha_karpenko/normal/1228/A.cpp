#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 41
#define MODULO 1000000007 
const ll MAXN = DIM * (DIM + 1) / 2;
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
ll l, r;
int main() {
	schnell;
	cin >> l >> r;
	for (ll i = l; i <= r; i++) {
		set<ll> S;
		ll x = i;
		ll flag = 0;
		while (x > 0) {
			if (S.count(x % 10) == 1) {
				flag = 1;
				break;
			}
			S.insert(x%10);
			x /= 10;
		}
		if (flag == 0) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}