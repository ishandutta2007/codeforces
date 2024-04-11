#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 2e5 + 33, mlg = 18, mod = 1e9 + 7;
struct record {
	int x = -1, y = -1, clen = 0, tlen = 0;
	bool operator<(const record& r) {
		if(y == -1 && r.y != -1) return false;
		return clen > r.clen || (clen == r.clen && tlen > r.tlen);
	}
	void up() {
		if(y==-1) tlen++;
		else clen++;
	}
	void merge(record &c) {
		if(y!=-1) return;
		if(c.x==-1) return;
		y = c.x, tlen += c.tlen;
	}
};
struct answer {
	int x, y, z, t, tlen = 0, clen = 0;
	void upd(record &a, record &b) {
		if(a.y>0&&b.y>0)
		if(pi{clen, tlen} < pi{a.clen+b.clen, a.tlen+b.tlen})
			x = a.x, y = a.y, z = b.x, t = b.y, tie(clen, tlen) = pi{a.clen+b.clen, a.tlen+b.tlen};
	}
};
int n;
vector<vi> g;
answer ans;
//{common, total}
record dfs(int v, int p) {
	record f, s, t;
	for(auto i : g[v]) {
		if(i == p) continue;
		record q = dfs(i, v);
		if(q < f) {
			t=s,s=f,f=q;
		} else if(q < s) {
			t=s,s=q;
		} else if(q < t) t = q;
	}
	if(f.y==-1) f.merge(s);
	else s.merge(t);
	ans.upd(f, s);
	if(f.x == -1) f.x = v;
	f.up();
//	cout << v << " " <<f.x << " " << f.y << "\n";
	return f;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int r = 1;
	for(int i = 1; i <= n; i++)
		if(g[i].size()>g[r].size()) r= i;
	dfs(r, r);
	cout << ans.x << " " << ans.t << "\n" << ans.y << " " << ans.z;
}