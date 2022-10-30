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
struct node {
	ll fi, sc, w;
};
ll n, m,ans[DIM],P[DIM],child[DIM],res = 0;
pp ask[DIM];
node ver[DIM];
bool mc(node a, node b) {
	return a.w < b.w;
}
ll F(ll x) {
	if (x == P[x])return x;
	P[x] = F(P[x]);
	return P[x];
}
void unite(ll x, ll y) {
	x = F(x);
	y = F(y);
	if (x == y)return;
	if (rand() % 2) {
		P[x] = y;
		res -= (child[x] - 1) * child[x] / 2;
		res -= child[y] * (child[y] - 1) / 2;
		child[y] += child[x];
		res += child[y] * (child[y] - 1) / 2;
	}
	else {
		P[y] = x;
		res -= (child[x] - 1) * child[x] / 2;
		res -= child[y] * (child[y] - 1) / 2;
		child[x] += child[y];
		res += child[x] * (child[x] - 1) / 2;
	}
}
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n) {
		P[i] = i;
		child[i] = 1;
	}
	forn(i, n - 1) {
		cin >> ver[i].fi >> ver[i].sc >> ver[i].w;
	}
	sort(ver + 1, ver  + n,mc);
	forn(i, m) {
		cin >> ask[i].fi;
		ask[i].sc = i;
	}
	sort(ask + 1, ask + 1 + m);
	ll pos = 1;
	for (ll i = 1; i <= m; i++) {
		while (pos<n && ver[pos].w <= ask[i].fi) {
			unite(ver[pos].fi, ver[pos].sc);
			pos++;
		}
		ans[ask[i].sc] = res;
	}
	for (ll i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
// abc acb bac bca cab cba