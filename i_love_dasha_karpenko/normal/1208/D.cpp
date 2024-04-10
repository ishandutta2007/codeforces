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
ll n, A[DIM],ans[DIM],fen[DIM];
void add(ll pos, ll x) {
	for (ll i = pos; i <= n; i += (i & -i))fen[i] += x;
}
ll sum(ll pos) {
	ll ret = 0;
	for (ll i = pos; i > 0; i -= (i & -i))ret += fen[i];
	return ret;
}
inline ll F(ll x) {
	return (x + 1) * x / 2-sum(x);
}
ll bin(ll L, ll R,ll need) {
	while (R-L>1) {
		ll tm = (L + R) / 2;
		if (F(tm) > need)R = tm - 1;
		else L = tm;
	}
	if (F(R)==need)
	return R;
	return L;
}
int main() {
	schnell;
	
	cin >> n;
	forn(i, n)cin >> A[i];
	for (ll i = n; i >= 1; i--) {
		ans[i] = bin(0, n,A[i])+1;
		add(ans[i], ans[i]);
	}
	forn(i, n)cout << ans[i] << ' ';
	cout << endl;
	return 0;
}