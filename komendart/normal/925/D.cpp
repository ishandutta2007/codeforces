#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)1e9 + 7;
const dbl eps = (dbl)1e-8;
const int maxn = (int)3e5 + 5;
const dbl pi = acos(-1);

int n, m;
vector <int> a[maxn], vc[maxn], v0;
int t0[maxn], t1[maxn], t[maxn];
int ans;
int cnt;
vector <int> vans;

void dfs(int v, int z) {
	if (t[v] || v == 0)
		return;
	t[v] = z;
	vc[z].pb(v);
	I(to, a[v]) {
		dfs(to, z);
	}
}

int main() {
//	fin("t.in");
	sync;
	cin >> n >> m;
	F(i, 0, m) {
		int x, y;
		cin >> x >> y; --x; --y;
		a[x].pb(y);
		a[y].pb(x);
	}
	clean(t0);
	v0.clear();
	t0[0] = 1;
	I(to, a[0]) {
		t0[to] = 1;
		v0.pb(to);
	}
	ans = inf;
	clean(t);
	cnt = 0;
	I(v, v0) {
		I(to, a[v]) {
			if (to != 0 && !t0[to]) {
				ans = 5;
				vans.clear();
				vans.pb(0);
				vans.pb(v);
				vans.pb(to);
				vans.pb(0);
				vans.pb(n - 1);
			}
		}
		if (t[v])
			cont;
		++cnt;
		vc[cnt].clear();
		dfs(v, cnt);
	}
	E(i, 1, cnt) {
		if (ans < inf)
			break;
		int u = -1;
		I(v, vc[i]) {
			if (sz(a[v]) != sz(vc[i]))
				u = v;
		}
//		cout << i << " " << sz(vc[i]) << endl;
//		cout << "u = " << u << endl;
		if (u == -1)
			cont;
		clean(t1);
		t1[u] = 1;
		I(to, a[u]) {
			t1[to] = 1;
		}
		I(to, a[u]) {
			if (to == 0 || ans < inf)
				cont;
			I(to1, a[to]) {
				if (to1 != 0 && to1 != u && !t1[to1]) {
					ans = 6;
					vans.clear();
					vans.pb(0);
					vans.pb(u);
					vans.pb(to);
					vans.pb(to1);
					vans.pb(u);
					vans.pb(n - 1);
					break;
				}
			}
		}
		assert(ans < inf);
	}
	memset(t, -1, sizeof t);
	vector <int> q;
	q.pb(0);
	int l = 0;
	t[0] = 0;
	while (l < sz(q)) {
		int v = q[l++];
		I(to, a[v]) {
			if (t[to] != -1)
				cont;
			t[to] = v;
			q.pb(to);
		}
	}
	if (t[n - 1] != -1) {
		int v = n - 1;
		vector <int> vc;
		while (v != 0) {
			vc.pb(v);
			v = t[v];
		}
		vc.pb(0);
		reverse(all(vc));
		if (sz(vc) < sz(vans) || sz(vans) == 0) {
			vans = vc;
			ans = sz(vans);
		}
	}


	if (ans < inf)
		cout << ans - 1 << endl;
	else
		cout << -1 << endl;
	if (ans < inf) {
		I(x, vans) {
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}