/**
 *	author:   fractal
 *	timus: 288481RF
 *	created: 03/10/21 20:41
**/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define nl printf("\n");
#define clbuff fflush(stdin);

mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
 
const int N = 1e3 + 2;
const int M = 1e5;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e18;
const ld pi2 = 2.0 * 3.141592;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void files() {
	#ifndef PC
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
}

int mul(int a, int b) {
	return a * 1LL * b % mod;
}

int n, m, ans, gl[N], lg[N], clc[N][N];
vi g[N], h[N];
queue <int> q;

void bfs1(int r) {
	for (int i = 1; i <= n; ++i)
		gl[i] = inf;
	gl[r] = 0;
	q.push(r);
	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (gl[to] > gl[v] + 1) {
				gl[to] = gl[v] + 1;
				q.push(to);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		lg[i] = gl[i];
		for (auto to : g[i]) {
			if (gl[to] + 1 == gl[i] && gl[i] != 0) {
				h[i].pb(to);
				h[to].pb(i);			
			}
		}
	}
}

void bfs2(int r) {
	for (int i = 1; i <= n; ++i)
		gl[i] = inf;
	gl[r] = 0;
	q.push(r);
	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (gl[to] > gl[v] + 1) {
				gl[to] = gl[v] + 1;
				q.push(to);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (gl[i] + lg[i] == lg[r])
			cnt++;
	}
	if (cnt != lg[r] + 1) {
		ans = 0;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		if (gl[i] == 0 || lg[i] == 0)
			continue;
		for (auto to : h[i]) {
			if ((gl[to] + 1 == gl[i] || gl[i] == 0) && (lg[to] + 1 == lg[i] || lg[i] == 0)) {
				cnt++;		
			}
		}
		if (gl[i] + lg[i] == lg[r])
			continue;
		ans = mul(ans, cnt);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1, a, b; i <= m; ++i) {
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			for (int k = 1; k <= n; ++k)
				h[k].clear();
			ans = 1;
			bfs1(i);
			bfs2(j);			
			clc[i][j] = clc[j][i] = ans;
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cout << clc[i][j] << " \n"[j == n];
}