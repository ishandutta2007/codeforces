#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
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
ll t;

ll bin(ll l, ll r,ll val,ll side,ll mi) {
	while (l != r) {
		ll tm = (l + r) / 2;
		if (val / pow(2, side - tm) < (tm-mi + 1))l = tm + 1;
		else r= tm;
	}
	return val / pow(2, side - r) == (r-mi + 1);
}
int main() {
	schnell;
	cin >> t;
	forn(erere, t) {
		string s;
		cin >> s;
		ll res = 0;
		ll last1 = s.length() - 1;
		for (ll i = s.length() - 1; i >= 0; i--) {
			ll r = 0;
			if (s[i] == '1')last1 = i;
			for (ll j = last1; j < s.length(); j++) {
				if (r > (j - i + 1))break;
				r *= 2;
				r += s[j] - '0';
				if (r == (j - i + 1))res++;
			}
			
		}
		cout << res << endl;
	}
	return 0;
}