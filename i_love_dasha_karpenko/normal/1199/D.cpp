#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
struct node {
	ll l, r, end, val;
	bool operator < (const node& b)const {
		return val < b.val;
	}
	bool operator > (const node& b)const {
		return val > b.val;
	}
};
bool mc(node a, node b) {
	return a.l < b.l;
}
ll n, q, V[DIM], tree[DIM*4];
pp A[DIM];
void buildtree(ll t, ll L, ll R) {
	if (L == R) {
		tree[t] = V[L];
		return;
	}
	ll tm = (L + R) / 2;
	buildtree(t * 2 + 1, L, tm);
	buildtree(t * 2 + 2, tm + 1, R);
	tree[t] = max(tree[t * 2 + 2], tree[t * 2 + 1]);
}
ll mx(ll t, ll L, ll R, ll tl, ll tr) {
	if (tl <= L && R <= tr)return tree[t];
	if (tl > R || L > tr)return 0;
	ll tm = (L + R) / 2;
	return max(mx(t * 2 + 1, L, tm, tl, tr), mx(t * 2 + 2, tm + 1, R, tl, tr));
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i].fi;
		A[i].sc = 0;
	}
	cin >> q;
	forn(i, q) {
		ll mod;
		cin >> mod;
		if (mod == 1) {
			ll p, x; cin >> p >> x;
			A[p] = { x,i };

		}
		else {
			ll x; cin >> x;
			V[i] = x;
		}
	}
	buildtree(0, 1, q);
	for (ll i = 1; i <= n; i++) {
		cout << max(A[i].fi, mx(0, 1, q, A[i].sc, q)) << ' ';
	}
	cout << endl;
	return 0;
}