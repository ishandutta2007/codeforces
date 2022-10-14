// Problem: C. Trees of Tranquillity
// Contest: Codeforces - Codeforces Round #722 (Div. 1)
// URL: https://codeforces.com/contest/1528/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 1<<19;
int n, tin[N], tout[N], timer = 0;
vector<vector<int>> g,k;
int ans = 0, cur = 0;
void dfs(int v, int p) {
	tin[v] = timer++;
	for(int i : g[v]) {
		dfs(i, v);
	}
	tout[v] = timer;
}
template<class Node>
struct SegTree {
    vector<Node> tree;
    int n;
    SegTree(int n) : tree(4*n), n(n) {}
    Node query(int v, int l, int r, int ql, int qr) {
        if(r < ql || qr < l) return Node();
        if(ql <= l && r <= qr) return tree[v];
        int mid = (l+r)/2;
        tree[v].push(tree[2*v], tree[2*v+1], l, r, mid);
        return query(2*v, l, mid, ql, qr) + query(2*v+1, mid+1, r, ql, qr);
    }
    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    template<class F>
    void update(int v, int l, int r, int ql, int qr, F f) {
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            f(tree[v], l, r);
            return;
        }
        int mid = (l+r)/2;
        tree[v].push(tree[2*v], tree[2*v+1], l, r, mid);
        update(2*v, l, mid, ql, qr, f);
        update(2*v+1, mid+1, r, ql, qr, f);
        tree[v] = tree[2*v]+tree[2*v+1];
    }
    template<class F>
    void update(int l, int r, F f) {
        update(1, 0, n-1, l, r, f);
    }
};
const int mod = 998244353;
struct Node {
    int lazy = -1;
    int cnt = -1;
    friend Node operator+(const Node &a, const Node &b) {
        Node res;
        res.cnt = max(a.cnt, b.cnt);
        return res;
    }
    void push(Node &l, Node &r, int nl, int nr, int nm) {
        if(lazy == -1) return;
        l.apply(lazy, nl, nm);
        r.apply(lazy, nm+1, nr);
        lazy = -1;
    }
    void apply(int O, int L, int R) {
    	lazy = O;
    	cnt = O;
    }
};
SegTree<Node> st(1);
vector<int> LL;
void enable(int v) {
	int par = st.query(tin[v], tout[v]-1).cnt;
	LL.push_back(par);
	if(par >= 0) {
		if(tin[par] < tin[v])
		st.update(tin[par], tout[par]-1, [&](Node &v, int nl, int nr) {
            v.apply(-2, nl, nr);
        });
	} else cur++;
	st.update(tin[v], tout[v]-1, [&](Node &vV, int nl, int nr) {
        vV.apply(v, nl, nr);
    });
}
void disable(int v) {
	int par = LL.back();
	if(par >= 0) {
		if(tin[par] < tin[v])
		st.update(tin[par], tout[par]-1, [&](Node &v, int nl, int nr) {
            v.apply(par, nl, nr);
        });
	} else {
		cur--;
		st.update(tin[v], tout[v]-1, [&](Node &v, int nl, int nr) {
       		v.apply(-2, nl, nr);
    	});
	}
	LL.pop_back();
}

void solve(int v, int p) {
	enable(v);
	for(int i : k[v]) {
		solve(i, v);
	}
	//cout << v << " - " << cur << endl;
	ans = max(ans, cur);
	disable(v);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
		multitest([&](){
		cin >> n;
		st = SegTree<Node>(n);
		k = g = vector<vector<int>>(n);
		for(int t, i = 1; i < n; i++) {
			cin >> t;
			k[t-1].push_back(i);
		}
		for(int t, i = 1; i < n; i++) {
			cin >> t;
			g[t-1].push_back(i);
		}
		timer = 0;
		ans = 0;
		dfs(0, 0);
		solve(0 ,0);
		cout << ans << '\n';
	});
}