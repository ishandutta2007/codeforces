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
ll D1[DIM], D2[DIM],A[DIM];
int main() {
	schnell;
	ll t; cin >> t;
	forn(e, t) {
		ll n, a, b;
		cin >> n >> a >> b;
		string s; cin >> s;
		ll res = 0,lr1 = 0,lr2 = 0;
		D1[1] = b * 2 + a;
		D2[1] = b * 3 + a * 2;
		for (ll i = 1; i < s.length(); i++) {
			if (s[i - 1] == '0' && s[i] == '0')A[i] = 0;
			else A[i] = 1;
		}
		A[n] = 0;
		D1[0] = b ;
		D2[0] = INF;
		for (ll i = 1; i <= n; i++) {
			if (A[i] == 1) {
				D2[i] = min(D2[i - 1], D1[i - 1] + a) + b * 2 + a;
				D1[i] = INF;
			}
			else {
				D2[i] = min(D2[i - 1], D1[i - 1] + a) + a + b * 2;
				D1[i] = min(D1[i - 1], D2[i - 1] + a) + a+b;
			}
		}
		cout << D1[n] << endl;
	}
	
	return 0;
}