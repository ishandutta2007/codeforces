#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long ll;
typedef long double ld;
#define DIM 2007
#define DIM2 1000007
#define MODULO 1000000007
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long INF = 10E16;
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
string s;
ll r1, r2;
vector<ll> res;
int main() {
	schnell;
	cin >> s;
	ll n = s.length()-1;
	for (ll i = n; i >=0; i--) {
		if (s[i] == '0') {
			r1++;
			res.pb(0);
		}
		else {
			if (r1 == r2) {
				r1++;
				res.pb(0);
			}
			else {
				res.pb(1);
			}
			r2++;
		}

	}
	for (ll i = n; i >= 0; i--)cout << res[i];
	cout << endl;
	return 0;
}