
/*
    Im not gonna run away, I never go back on my word! Thats my nindo: my ninja way. Naruto
























































*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e5 + 2;
const int M = 2e6 + 2;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e16;

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int T, n, m, p[N], h[N], sz[N], good[N], bad[N];
bool f;
vi g[N];

void dfs(int v = 1, int par = 0) {
	sz[v] = p[v];
	for (auto to : g[v]) {
		if (to == par)
			continue;
		dfs(to, v);
		sz[v] += sz[to];
	}		
}

void lol(int v = 1, int par = 0) {
	if (abs(sz[v] - h[v]) % 2 != 0) {
		f = 0;
	}
	bad[v] = (sz[v] - h[v]) / 2;
	good[v] = sz[v] - bad[v];
	for (auto to : g[v]) {
		if (to == par)
			continue;
		lol(to, v);
	}
}

void check(int v = 1, int par = 0) {
	//~ cerr << v << " : " << good[v] << " " << bad[v] << " " << h[v] << '\n';
	if (good[v] < 0 || bad[v] < 0)
		f = 0;
	for (auto to : g[v]) {
		if (to == par)
			continue;
		if (good[to] > good[v]) {
			f = 0;
		}
		good[v] -= good[to];
		check(to, v);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		f = 1;
		p[0] = inf;
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &p[i]);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &h[i]);
		for (int i = 1, v, u; i < n; ++i) {
			scanf("%d %d", &v, &u);
			g[u].pb(v);
			g[v].pb(u);			
		}
		dfs();
		lol();
		check();
		if (f)
			printf("YES\n");
		else
			printf("NO\n");
		//~ return 0;
	}
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/