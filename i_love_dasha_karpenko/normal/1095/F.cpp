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
struct node {
	ll fi, sc, tr;
};
ll n, m, N[DIM],P[DIM],M[DIM];
node J[DIM];
pp mi = { INF,0 };
ll res = 0;
ll F(ll x) {
	if (x == P[x])return x;
	P[x] = F(P[x]);
	return P[x];
}
ll cost(ll x,ll y) {
	if (y == mi.sc)swap(x, y);
	if (x == mi.sc) {
		return mi.fi + M[y];
	}
	return M[x] + M[y] + mi.fi * 2;
}
ll cw(ll x, ll y, ll w) {
	if (y == mi.sc)swap(x, y);
	if (x == mi.sc) {
		return w;
	}
	return w + mi.fi+min(M[x],M[y]);
}
void unite(ll x, ll y,ll c) {
	x = F(x); y = F(y);
	if (x == y)return;
	res += c;
	ll r;
	if (x == mi.sc)r = 2;
	else if (y == mi.sc)r = 1;
	else r = rand() % 2 + 1;
	if (r==1) {
		P[x] = y;
		M[y] = min(M[y], M[x]);
	}
	if (r==2){
		P[y] = x;
		M[x] = min(M[x], M[y]);
	}
}
bool mc(node a, node b) {
	return a.tr < b.tr;
}
int main() {
	schnell;
	cin >> n >> m;
	
	forn(i, n) {
		cin >> N[i];
		mi = min(mi, { N[i],i });
	}
	for (ll i = 1; i <= n; i++) {
		M[i] = N[i];
		P[i] = i;
	}
	forn(i, m) {
		cin >> J[i].fi >> J[i].sc >> J[i].tr;
	}
	sort(J + 1, J + 1 + m,mc);
	forn(i, m) {
		ll x = J[i].fi, y = J[i].sc, w = J[i].tr;
		x = F(x); y = F(y);
		if (x == y)continue;
		if (cost(x,y) > cw(x,y,w))
			unite(x, y, w);
	}
	forn(i, n) {
		unite(mi.sc, i,mi.fi+M[F(i)]);
	}
	cout << res << endl;
	return 0;
}