#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 1007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
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
ll x, n;
ll P(ll a, ll b) {
	a %= MOD;
	ll mu = a,ret = 1;
	
	while (b>0) {
		if (b & 1)ret =(ret* mu)%MOD;
		mu = (mu * mu) % MOD;
		b /= 2;
	}
	return ret;
}
ll P1(ll a, ll b) {
	ll ret = 1;
	a %= MOD;
	forn(i,b)
		ret = (ret*a)%MOD;
	return ret;
}
ll fm(ll a, ll b) {
	ll t = b;
	if (b > a)b = 1;
	while (a >= b) {
		if (a / b < t)break;
		b *= t;
	}
	
	return b;
}
ll g(ll a, ll b) {
	ll t = fm(a,b);
	ll ret = 1,hw = 0;
	while (t>1) {
		ll next = min(a, t * b-1);
		ll mult = a / t-hw;
		hw += mult;
		//if (a == next && next % t == 0 && next!=t*b)mult++;
		ret = (ret*P(t,mult))%MOD;
		//if (t >= sqrt(MAXN))break;
		t /= b;
	}
	
	return ret;
}
ll Checksimp(ll a) {
	if (a == 1)return 0;
	ll sq = sqrt(a),flag = 0;
	for (ll i = 2; i <= sq; i++) {
		if (a % i == 0) {
			flag = 1;
			break;
		}
	}
	return 1 - flag;
}
int main() {
	schnell;
	cin >> x >> n;
	ll sq = sqrt(x),res = 1;
	for (ll i = 1; i <= sq; i++) {
		if (x % i == 0) {
			
			if (Checksimp(i)) {
				//cout << i << endl;
				res = (res * g(n, i)) % MOD;
			}
			if (x / i != i && Checksimp(x / i)) {
				//cout << x / i << endl;
				res = (res * g(n, x/i)) % MOD;
			}
		}
	}
	cout << res << endl;
	return 0;
}