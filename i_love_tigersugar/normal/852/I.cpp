#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int MOD2 = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct Query {
	static const int MAGIC = 320;
	int l, r, a, idx;
	int operator < (const Query& rhs) {
		if (l / MAGIC != rhs.l / MAGIC) return l / MAGIC < rhs.l / MAGIC;
		return r < rhs.r;
	}
};
const int MAXN = 1e5 + 5;
const int LOGN = 20;
int n, q;
int a[MAXN];
int f[MAXN];
vector<int> adj[MAXN];
Query query[MAXN];
int p[LOGN][MAXN];
int vis[MAXN];
int lev[MAXN];
int tin[MAXN];
int tou[MAXN];
int idx[MAXN << 1];
int tms;

void dfs(int u, int dad = -1) {
	idx[tin[u] = tms++] = u;
	for (int i = 1; i < LOGN; i++) p[i][u] = p[i - 1][p[i - 1][u]];
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad) {
			lev[v] = lev[u] + 1;
			p[0][v] = u;
			dfs(v, u);
		}
	}
	idx[tou[u] = tms++] = u;
}
int isparent(int u, int v) {
	return tin[u] <= tin[v] && tou[u] >= tou[v];
}
int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	if (isparent(v, u)) return v;
	for (int i = LOGN - 1; i >= 0; i--) {
		if (lev[p[i][u]] >= lev[v]) {
			u = p[i][u];
		}
	}
	for (int i = LOGN - 1; i >= 0; i--) {
		if (p[i][u] != p[i][v]) {
			u = p[i][u];
			v = p[i][v];
		}
	}
	return p[0][u];
}

long long tot;
int cnt[2][MAXN];

void add(int u) {
    tot += cnt[a[u] ^ 1][f[u]];
    cnt[a[u]][f[u]]++;
}
void rem(int u) {
    tot -= cnt[a[u] ^ 1][f[u]];
    cnt[a[u]][f[u]]--;
}
void deal(int u) {if (vis[u] ^= 1) add(u); else rem(u);}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    vi dc;
    FOR(i, 0, n) cin >> f[i], dc.pb(f[i]);
    sort(all(dc)), uni(dc);
    FOR(i, 0, n) f[i] = lower_bound(all(dc), f[i]) - dc.begin();
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    cin >> q;
    dfs(0);
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v; u--, v--;
		if (lev[u] > lev[v]) swap(u, v);
		int a = lca(u, v);
		if (u == a) {
			query[i].l = tin[u];
			query[i].r = tin[v];
			query[i].a = -1;
		}
		else {
			query[i].l = tou[u];
			query[i].r = tin[v];
			query[i].a = a;
		}
		query[i].idx = i;
	}
	static long long ans[MAXN];
	sort(query, query + q);
	int l = 0, r = -1;
	for (int i = 0; i < q; i++) {
		while (l < query[i].l) deal(idx[l++]);
		while (l > query[i].l) deal(idx[--l]);
		while (r < query[i].r) deal(idx[++r]);
		while (r > query[i].r) deal(idx[r--]);
		if (~query[i].a) deal(query[i].a);
		ans[query[i].idx] = tot;
		if (~query[i].a) deal(query[i].a);
	}
	FOR(i, 0, q) {
	    cout << ans[i] << "\n";
	}
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}