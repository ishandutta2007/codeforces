//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

struct node{
	int c0, c1;
	ll s0, s1;
	node(){
		c0 = c1 = s0 = s1 = 0;
	}
	node(int c_0, int c_1, ll s_0, ll s_1){
		c0 = c_0, c1 = c_1, s0 = s_0, s1 = s_1;
	}
};

node mrg(node a, node b){
	a.c0 += b.c0;
	a.c1 += b.c1;
	a.s0 += b.s0;
	a.s1 += b.s1;
	return a;
}
node nt(node a){
	swap(a.c0, a.c1);
	swap(a.s0, a.s1);
	return a;
}

int n, pr[maxn], sz[maxn], t, st[maxn], ft[maxn], a[maxn], par[maxn], lz[maxn << 2], hd[maxn];
vector<pii> g[maxn];
node seg[maxn << 2];

void bld(int id, int s, int e){
	if(e - s == 1){
		seg[id] = node(1, 0, pr[a[s]], 0);
		return;
	}
	int mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}
void upd(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = nt(seg[id]);
		lz[id] ^= 1;
		return;
	}
	int mid = (s + e) >> 1;
	if(lz[id]){
		seg[lc] = nt(seg[lc]);
		lz[lc] ^= 1;
		seg[rc] = nt(seg[rc]);
		lz[rc] ^= 1;
		lz[id] = 0;
	}
	upd(lc, s, mid, l, r);
	upd(rc, mid, e, l, r);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}

void dfs(int v){
	sz[v] = 1;
	for(pii u : g[v]){
		if(u.S == pr[v]) continue;
		pr[u.F] = u.S;
		par[u.F] = v;
		dfs(u.F);
		sz[v] += sz[u.F];
	}
	return;
}
void dfs2(int v){
	int bg = 0;
	a[st[v] = t++] = v;
	for(pii u : g[v]){
		if(u.S == pr[v]) continue;
		if(sz[u.F] > sz[bg]) bg = u.F;
	}
	if(bg){
		hd[bg] = hd[v];
		dfs2(bg);
	}
	for(pii u : g[v]){
		if(u.F == bg || u.S == pr[v]) continue;
		hd[u.F] = u.F;
		dfs2(u.F);
	}
	ft[v] = t;
	return;
}
void upd(int v){
	while(v){
		upd(1, 0, n, st[hd[v]], st[v] + 1);
		v = par[hd[v]];
	}
	return;
}

vector<int> vec;

void solve(int id, int s, int e){
	if(e - s == 1){
		if(seg[id].c1) vec.pb(seg[id].s1);
		return;
	}
	int mid = (s + e) >> 1;
	if(lz[id]){
		seg[lc] = nt(seg[lc]);
		lz[lc] ^= 1;
		seg[rc] = nt(seg[rc]);
		lz[rc] ^= 1;
		lz[id] = 0;
	}
	solve(lc, s, mid);
	solve(rc, mid, e);
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(Mp(u, i));
		g[u].pb(Mp(v, i));
	}
	dfs(1);
	hd[1] = 1;
	dfs2(1);
	bld(1, 0, n);
	int q, cn = 1;
	cin >> q;
	upd(1);
	while(q != 3){
		assert(q != 0);
		if(q == 1){
			int v;
			cin >> v;
			upd(v);
			cn++;
			if(2 * seg[1].c1 == cn) cout << seg[1].s1 << "\n";
			else cout << "0\n";
		}
		else{
			if(2 * seg[1].c1 != cn){
				cout << "0\n";
			}
			else{
				vec.clear();
				solve(1, 0, n);
				sort(all(vec));
				cout << Sz(vec) << " ";
				for(int i : vec){
					cout << i << " ";
				}
				cout << "\n";
			}
		}
		cout.flush();
		cin >> q;
	}
	
	return 0;
}