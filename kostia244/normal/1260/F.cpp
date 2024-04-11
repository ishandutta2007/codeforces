//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1000000007;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e5 + 55;
void norm(int &x) {
	if(x<0) x+=mod;
	if(x>=mod) x-=mod;
}
int nrm(int x) {
	norm(x);
	return x;
}
struct _fenwick {
	int n, t[maxn];
	void init(int _n) {
		n = _n;
		memset(t, 0, sizeof t);
	}
	void add(int i, int x) {
		while(i <= n) {
			norm(t[i] += x);
			i += i&-i;
		}
	}
	int get(int i) {
		int ans = 0;
		while(i) {
			norm(ans += t[i]);
			i -= i&-i;
		}
		return ans;
	}
};
struct fenwick {
	_fenwick x, y;
	void init(int n) {
		x.init(n);
		y.init(n);
	}
	void add(int l, int r, int v) {
		norm(v);
		x.add(l, ((l-1)*1ll*v)%mod);
		x.add(r+1, nrm(-((r*1ll*v)%mod)));
		y.add(l, v);
		y.add(r+1, nrm(-v));
	}
	int get(int i) {
		return nrm(((i*1ll*y.get(i))%mod)-x.get(i));
	}
	int get(int l, int r) {
		return nrm(get(r)-get(l-1));
	}
};
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = (r*1ll*a)%mod;
		a = (a*1ll*a)%mod;
		p>>=1;
	}
	return r;
}
int n, ans = 0, f = 1, l[maxn], r[maxn], sz[maxn], maxch[maxn], cmb[maxn], inv[maxn];
vector<int> comp, g[maxn];
bitset<100100> isCentroid;
fenwick cnt;
void sizes(int v, int p) {
	comp.pb(v);
	sz[v] = 1;
	maxch[v] = 0;
	for(auto i : g[v])
		if(i!=p&&!isCentroid[i]) {
			sizes(i, v);
			sz[v] += sz[i];
			maxch[v] = max(maxch[v], sz[i]);
		}
}

int findCentroid() {
	int c = comp[0];
	for(auto i : comp) {
		maxch[i] = max(maxch[i], (int)comp.size()-sz[i]);
		if(maxch[c]>maxch[i]) c=i;
	}
	return c;
}

void search(int v, int p, int rem, int d) {
	int t = (cmb[v]*1ll*d)%mod;
	if(rem) t=nrm(-t);
	cnt.add(l[v], r[v], t);
	for(auto i : g[v])
		if(i!=p&&!isCentroid[i]) {
			search(i, v, rem, d+1);
		}
}
void update(int v, int p, int d) {
	int t = (cnt.get(l[v], r[v])*1ll*inv[v])%mod;
	norm(ans += t);
	for(auto i : g[v])
		if(i!=p&&!isCentroid[i]) {
			update(i, v, d+1);
		}
}
void decompose(int v) {
	sizes(v, v);
	int c = findCentroid();
	comp.clear();
	isCentroid[c] = 1;
	search(c, c, 0, 0);
	norm(ans+=(cnt.get(l[c], r[c])*1ll*inv[c])%mod);
	for(auto i : g[c]) {
		if(isCentroid[i]) continue;
		search(i, c, 1, 1);
		update(i, c, 1);
		search(i, c, 0, 1);
	}
	search(c, c, 1, 0);
	for(auto i : g[c])
		if(!isCentroid[i])
			decompose(i);
}

int solve() {
	cnt.init(maxn-5);
	decompose(1);
	return ans;
}

int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i], f = (f*1ll*(r[i]-l[i]+1))%mod;
	for(int i = 1; i <= n; i++) {
		inv[i] = bp(r[i]-l[i]+1, mod-2);
		cmb[i] = (f*1ll*inv[i])%mod;
	}
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	cout << solve();
}