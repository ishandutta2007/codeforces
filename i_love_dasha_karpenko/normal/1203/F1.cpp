#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
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
bool const operator<(const pp& a,const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n, r;
vector<pp> V1, V2;
bool mc(pp x, pp y) {
	return x.fi + x.sc > y.sc + y.fi;
}
int main() {
	schnell;
	cin >> n >> r;
	forn(i, n) {
		ll x, y; cin >> x >> y;
		if (y > 0)V1.pb({ x,y });
		else V2.pb({ x,y });
	}
	sort(V1.begin(), V1.end());
	ll flag = 0;
	for (pp to : V1) {
		if (to.fi > r) {
			flag = 1;
			break;
		}
		r += to.sc;
	}
	for (ll i = 0; i < V2.size(); i++) {
		V2[i].fi = max(V2[i].fi, -V2[i].sc);
	}
	sort(V2.begin(), V2.end(), mc);
	for (pp to : V2) {
		if (to.fi > r) {
			flag = 1;
			break;
		}
		r += to.sc;
	}
	if (flag == 1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}