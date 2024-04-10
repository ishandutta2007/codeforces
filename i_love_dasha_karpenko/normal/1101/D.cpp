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
#define MODULO 998244353  
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
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

ll n,A[DIM],erat[DIM],vis[DIM],P[DIM];
vector<ll> T,G[DIM];
map<ll,ll> M[DIM];
void topsort(ll x) {
	vis[x] = 1;
	for (ll to : G[x]) {
		if (vis[to] == 0) {
			P[to] = x;
			topsort(to);
		}
	}
	T.pb(x);
}
int main() {
	schnell;
	cin >> n;
	ll res = 0;
	forn(i, n) {
		cin >> A[i];
		if (A[i] > 1)res = 1;
	}
	for (ll i = 2; i <= n; i++) {
		if (erat[i] == 0) {
			for (ll j = i * i; j <= n; j += i)erat[j] = 1;
		}
	}
	forn(i, n - 1) {
		ll x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	erat[1] = 1;
	forn(i, n) {
		if (G[i].size() == 1) {
			topsort(i);
			break;
		}
	}
	
	for (ll to : T) {
		for (ll i = 1; i <= sqrt(A[to]); i++) {
			if (A[to] % i == 0) {
				if (erat[i]==0)M[to][i] = 1;
			}
			if (A[to] % i == 0 && A[to]/i!=i &&  A[to] % (A[to] / i) == 0) {
				if (erat[A[to] / i] == 0)M[to][A[to] / i] = 1;
			}
		}
		for (ll vert : G[to]) {
			if (vert == P[to])continue;
			for (auto div : M[to]) {
				res = max(res, M[to][div.first] + M[vert][div.first]);
				res = max(res, M[to][div.first] = max(M[vert][div.first]+1,div.second));
			}
		}
	}
	cout << res << endl;
	return 0;
}