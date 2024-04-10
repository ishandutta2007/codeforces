#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 1000007
#define DIM2 DIM*150
#define MODULO 1000000007
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
ll n,P[DIM],pref[DIM],suf[DIM];
string s;
int main() {
	schnell;
	cin >> n;
	cin >> s; ll l = s.length();
	for (ll i = 0; i < l; i++) {
		if (i>0)
		P[i] = P[i - 1];
		if (s[i] == '(')P[i]++;
		else P[i]--;
	}
	pref[0] = INF;
	for (ll i = 0; i < l; i++) {
		if (i > 0)pref[i] = pref[i - 1];
		pref[i] = min(pref[i], P[i]);
	}
	suf[l - 1] = INF;
	for (ll i = l - 1; i >= 0; i--) {
		if (i < l - 1)suf[i] = suf[i + 1];
		suf[i] = min(suf[i], P[i]);
	}
	ll res = 0;
	for (ll i = 0; i < l; i++) {
		ll r = INF;
		if (i > 0)r = min(r, pref[i - 1]);
		if (s[i] == '(') {
			r = min(suf[i] - 2,r);
			if (P[l - 1] - 2 != 0)r = -1;
		}
		else {
			r = min(suf[i] + 2, r);
			if (P[l - 1] + 2 != 0)r = -1;
		}
		if (r < 0)res++;
	}
	cout << l-res << endl;
}