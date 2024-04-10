#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 400007
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
ll T;
vector<ll> A[DIM];
bool vis[DIM];
int main() {
	schnell;
	cin >> T;
	while (T > 0) {
		T--;
		ll n, m;
		cin >> n >> m;
		forn(i, n * 3)A[i].clear();
		vector<pp> V;
		forn(i, m) {
			ll x, y; cin >> x >> y;
			A[x].pb(y);
			A[y].pb(x);
			V.pb({ x,y });
		}
		vector<pp> indset;
		forn(i, n*3) {
			indset.pb({ A[i].size(),i });
		}
		sort(indset.begin(), indset.end());
		vector<ll> ans;
		forn(i, n*3)vis[i] = false;
		for (pp to : indset) {
			if (vis[to.sc])continue;
			for (ll x : A[to.sc])vis[x] = true;
			ans.pb(to.sc);
		}
		if (ans.size() >= n) {
			cout << "IndSet" << endl;
			for (ll i = 0; i < n; i++)cout << ans[i] << ' ';
			cout << endl;
			continue;
		}
		ans.clear();
		forn(i, n * 3)vis[i] = false;
		vector<pp> match;
		for (ll i = 0; i < m; i++) {
			pp to = V[i];
			match.pb({ A[to.fi].size() + A[to.sc].size(),i + 1 });
		}
		sort(match.begin(), match.end());
		for (pp to : match) {
			if (vis[V[to.sc - 1].fi] || vis[V[to.sc - 1].sc])continue;
			vis[V[to.sc - 1].fi] = 1; vis[V[to.sc - 1].sc] = 1;
			ans.pb(to.sc);
		}
		if (ans.size() >= n) {
			cout << "Matching" << endl;
			for (ll i = 0; i < n; i++)cout << ans[i] << ' ';
			cout << endl;
			continue;
		}
		cout << "Impossible" << endl;
	}
	return 0;
}