#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 67, MOD = 1e9 + 7, sigma = 26;
     
int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;

int add_str(string s)
{
	int cur = 0;
        for(auto c: s)
        {
            if(!to[cur][c - 'a'])
            {
                to[cur][c - 'a'] = sz++;
                len[to[cur][c - 'a']] = len[cur] + 1;
            }
            cur = to[cur][c - 'a'];
        }
        term[cur] = cur; 
	return cur;
}
     
void push_links()
    {
        vector<int> que(sz);
        int st = 0, fi = 1;
        que[0] = 0;
        while(st < fi)
        {
            int V = que[st++];
            int U = link[V];
            if(!term[V]) term[V] = term[U];
            for(int c = 0; c < sigma; c++)
                if(to[V][c])
                {
                    link[to[V][c]] = V ? to[U][c] : 0;
                    que[fi++] = to[V][c];
                }
                else
                {
                    to[V][c] = to[U][c];
                }
        }
}

//
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};
//#include "../data-structures/LazySegmentTree.h"


template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) { tree->set(l, r, val); });
	}
	int queryPath(int u, int v) { // Modify depending on problem
		int res = -1e9;
		process(u, v, [&](int l, int r) {
				res = max(res, tree->query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};
//

multiset<int> val[MAXN];
int w[MAXN];
vector<vector<int>> adj;
int main() {
	cin.tie(0)->sync_with_stdio(0);	
	int n, m;
	cin >> n >> m;
	string t;
	int x, y;
	vector<int> e;
	while(n--) {
		cin >> t;
		e.push_back(add_str(t));
		val[e.back()].insert(0);
	}
	push_links();
	adj.resize(sz);
	for(int i = 1; i < sz; i++) {
		adj[i].push_back(link[i]);
		adj[link[i]].push_back(i);
	}
	auto a = HLD<0>(adj);
	for(int i = 0; i < sz; i++) {
		if(val[i].size()) a.modifyPath(i, i, *val[i].rbegin());
	}
	while(m--) {
		cin >> t;
		if(t == "2") {
			cin >> t;
			int cur = 0, ans = -1;
			for(auto &i : t) {
				cur = to[cur][i-'a'];
				ans = max(ans, a.queryPath(0, cur));
			}
			cout << ans << '\n';
		} else {
			cin >> x >> y;--x;
			val[e[x]].erase(val[e[x]].find(w[x]));
			val[e[x]].insert(w[x] = y);
			a.modifyPath(e[x], e[x], *val[e[x]].rbegin());
		}
	}
	return 0;
}