#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM =BLOCK * BLOCK + 7;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
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
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}
struct node {
	ll fi, sc, pos;
};

ll n, m, k,A[DIM],Pref[DIM],M[DIM*10],result = 0,ans[DIM*10];
vector<node> Qe[BLOCK];
void add(ll x) {
	result += M[Pref[x] ^ k];
	M[Pref[x]]++;
}
void del(ll x) {
	M[Pref[x]]--;
	result -= M[Pref[x] ^ k];
}
bool mc(node a, node b) {
	return a.sc < b.sc;
}
int main() {
	schnell;
	cin >> n >> m >> k;
	forn(i, n)cin >> A[i];
	forn(i, n)Pref[i] = Pref[i - 1] ^ A[i];
	forn(i, m) {
		ll l, r; cin >> l >> r;
		Qe[l / BLOCK].pb({ l,r ,i});
	}
	for (ll i = 0; i < BLOCK; i++) {
		ll l = i * BLOCK, r = l;
		M[Pref[l]]++;
		result = 0;
		sort(Qe[i].begin(), Qe[i].end(),mc);
		for (node t : Qe[i]) {
			while (r < t.sc) {
				r++;
				add(r);
			}
			while (l + 1 > t.fi) {
				l--;
				add(l);
				
			}
			while (l + 1 < t.fi) {
				del(l);
				l++;
			}
			ans[t.pos] = result;
		}
		for (ll j = l-1; j <= r; j++)M[Pref[j]] = 0;
	}
	forn(i, m)cout << ans[i] << endl;
	return 0;
}