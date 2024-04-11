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
const int maxn = 1e5 + 33, mlg = 17, mod = 1e9 + 7;
//using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, q, b[maxn];
ll pref[maxn];
ll ans[maxn];
struct rsq {
	int C = 300;
	int n, val[maxn], lazy[maxn];
	void init(int sz) {
		n = sz;
	}
	int get(int i) {
		if(i<1) return 0;
		return val[i] + lazy[i/C];
	}
	int get(int l, int r) {
		return get(r) - get(l-1);
	}
	void add(int l, int x) {
		while(l <= n) {
			if(l%C==0&&l+C-1<=n) {
				lazy[l/C] += x;
				l += C;
			} else {
				val[l++] += x;
			}
		}
	}
};
struct query {
	int l, r, i;
	query(int l, int r, int i) : l(l), r(r), i(i) {
	}
};
struct aho {
	int to[maxn][26], link[maxn], cnt[maxn], sz = 1;
	vi col[maxn];
	vector<query> qs[maxn];
	vector<vi> g;
	rsq t;
	aho() {
		memset(to, 0, sizeof to);
	}
	void add(string &s, int id) {
		int cur = 0;
		for(auto c : s) {
			c-='a';
			if(!to[cur][c]) to[cur][c] = sz++;
			cur = to[cur][c];
		}
		col[cur].pb(id);
	}
	void mark(string &s, query q) {
		int cur = 0;
		for(auto c : s) {
			c-='a';
			cur = to[cur][c];
			qs[cur].pb(q);
		}
	}
	void push_links() {
		int q[maxn], s = 0, e = 0;
		q[e++] = 0;
		while(s < e) {
			int V = q[s++];
			int U = link[V];
			for(int i = 0; i < 26; i++) {
				if(!to[V][i]) {
					to[V][i] = to[U][i];
				} else {
					q[e++] = to[V][i];
					link[to[V][i]] = V?to[U][i]:0;
				}
			}
		}
		g.resize(sz);
		t.init(n);
		for(int i = 1; i < sz; i++)
			g[link[i]].pb(i);
	}
	void dfs(int v = 0) {
		for(auto i : col[v])
			t.add(i, 1);
		for(auto i : qs[v]) {
			ans[i.i] += t.get(i.l, i.r);
		}
		for(auto i : g[v]) {
			dfs(i);
		}
		for(auto i : col[v])
			t.add(i, -1);
	}
	int dfs2(int v = 0) {
		ll c = cnt[v];
		for(auto i : g[v]) {
			c += dfs2(i);
		}
		for(auto i : col[v]) {
			pref[i] += c;
		}
		return c;
	}
	void calc(string &s) {
		memset(cnt, 0, sizeof cnt);
		memset(pref, 0, sizeof pref);
		int cur = 0;
		for(auto c : s) {
			c-='a';
			cur = to[cur][c];
			cnt[cur]++;
		}
		dfs2();
	}
};
const int C = 333;
string s[maxn];
vector<query> qs[maxn];
aho a;
void kmp(int x) {
	int i = 0, j = -1;
	b[0] = -1;
	while(i < s[x].size()) {
		while(j!=-1&&s[x][j]!=s[x][i]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}
int occ(int x, int y) {//occurences of x in y
	kmp(x);
	int i = 0, j = 0, res = 0;
	while(i < s[y].size()) {
		while( j != -1 && s[y][i] != s[x][j]) j = b[j];
		i++, j++;
		if(j==s[x].size()) {
			res++, j = b[j];
		}
	}
	return res;
}
void solveheavy(int x) {
	a.calc(s[x]);
	pref[0] = 0;
	for(int i = 1; i <= n; i++) pref[i] += pref[i-1];
	for(auto i : qs[x]) {
		ans[i.i] = pref[i.r] - pref[i.l-1];
	}
}
void solvelight(int i) {
//	cout << i << " is light\n";
	for(auto j : qs[i]) {
		a.mark(s[i], j);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int l, r, k, i = 0; i < q; i++) {
		cin >> l >> r >> k;
		qs[k].emplace_back(l, r, i);
	}

	for(int i = 1; i <= n; i++) {
		a.add(s[i], i);
	}
	a.push_links();
	for(int i = 1; i <= n; i++) {
		if(s[i].size()>C) solveheavy(i);
		else solvelight(i);
	}
	a.dfs();
	for(int i = 0; i < q; i++)
		cout << ans[i] << "\n";
}