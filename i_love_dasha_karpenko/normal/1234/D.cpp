#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef int ll;
typedef long double ld;
#define DIM 100007
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
ll q;
string s;
ll tree[30][DIM * 4];
void buildtree(ll ti, ll v, ll tl, ll tr) {
	if (tl == tr) {
		if (s[tl] - 'a' == ti)tree[ti][v] = 1;
		return;
	}
	ll tm = (tl + tr) / 2;
	buildtree(ti, v * 2 + 1, tl, tm);
	buildtree(ti, v * 2 + 2, tm + 1, tr);
	tree[ti][v] = max(tree[ti][v * 2 + 1], tree[ti][v * 2 + 2]);
}
void tu(ll ti, ll v, ll tl, ll tr, ll pos, ll val) {
	if (tl > pos || tr < pos)return;
	if (tl == tr) {
		tree[ti][v] = val;
		return;
	}
	ll tm = (tl + tr) / 2;
	tu(ti, v * 2 + 1, tl, tm, pos, val);
	tu(ti, v * 2 + 2, tm + 1, tr, pos, val);
	tree[ti][v] = max(tree[ti][v * 2 + 1], tree[ti][v * 2 + 2]);
}
ll tf(ll ti, ll v, ll tl, ll tr, ll l, ll r) {
	if (tl > r || l > tr)return 0;
	if (l <= tl && tr <= r)return tree[ti][v];
	ll tm = (tl + tr) / 2;
	return max(tf(ti, v * 2 + 1, tl, tm, l, r), tf(ti, v * 2 + 2, tm + 1, tr, l, r));
}
int main() {
	schnell;
	cin >> s;
	ll n = s.length();
	for (ll i = 0; i < 30; i++) {
		buildtree(i, 0, 0, n - 1);

	}
	cin >> q;
	forn(qeq, q) {
		ll po; cin >> po;
		if (po == 1) {
			char ch; ll pos;
			cin >> pos >> ch;
			pos--;
			tu(s[pos] - 'a', 0, 0, n - 1, pos, 0);
			tu(ch - 'a', 0, 0, n - 1, pos, 1);
			s[pos] = ch;
		}
		else {
			ll l, r; cin >> l >> r;
			l--;
			r--;
			ll res = 0;
			for (ll i = 0; i < 30; i++)res += tf(i, 0, 0, n - 1, l, r);
			cout << res << endl;
		}
	}
	return 0;
}