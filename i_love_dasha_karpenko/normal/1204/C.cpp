#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long ll;
typedef long double ld;
#define DIM 107
#define DIM2 1000007
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
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n,m,D[DIM2],dist[DIM][DIM],P[DIM2];
vector<ll> A[DIM],pos[DIM];
queue<ll> Q;
void calcdist(ll x) {
	Q.push(x);
	dist[x][x] = 0;
	while (!Q.empty()) {
		ll t = Q.front();
		Q.pop();
		for (ll to : A[t]) {
			if (dist[x][to] == INF) {
				dist[x][to] = dist[x][t] + 1;
				Q.push(to);
			}
		}
	}
}
vector<ll> ans;
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		forn(j, n) {
			char x; cin >> x;
			if (x == '1') {
				A[j].pb(i);
			}
			dist[i][j] = INF;
		}
	}
	cin >> m;
	forn(i, m) {
		cin >> P[i];
	}
	forn(i, n) {
		calcdist(i);
	}
	D[1] = 1;
	for (ll i = 2; i <= m; i++) {
		D[i] = i;
		for (ll j = 1; j <= n; j++) {
			if (i - dist[P[i]][j]>0 && P[i - dist[P[i]][j]] == j) {
				D[i] = min(D[i], D[i - dist[P[i]][j]] + 1);
			}
		}
	}
	ll i = m;
	cout << D[m] << endl;
	ans.pb(P[m]);
	while (i > 1) {
		for (ll j = i - 1; j >= 1; j--) {
			if (dist[P[i]][P[j]] == (i - j)&& D[i]==D[j]+1) {
				i = j;
				break;
			}
		}
		ans.pb(P[i]);
	}
	for (i = ans.size() - 1; i >= 0; i--)cout << ans[i] << ' ';
	return 0;
	
}