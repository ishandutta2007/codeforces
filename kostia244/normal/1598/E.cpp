// Problem: E. Staircases
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

struct Counter {
	struct Node {
		int p, s, a;
		ll ans;
		Node(int tp = 0) : p(tp), s(tp), a(1), ans(tp) {}
		friend Node operator+(const Node &a, const Node &b) {
			Node res;
			res.p = a.p + (a.a == a.p ? b.p : 0);
			res.s = (b.a == b.s ? a.s : 0) + b.s;
			res.a = a.a+b.a;
			res.ans = a.ans + b.ans + a.s*b.p;
			return res;
		}
	};
	int n;
	vector<Node> tree;
	Counter(int n) : n(n), tree(4*n) {}
	ll flip(int pos) { ll old = tree[1].ans; flip(1, 0, n-1, pos); return tree[1].ans-old; }
	void flip(int v, int l, int r, int p) {
		if(p < l || r < p) return;
		if(l == r) {
			tree[v] = Node(1-tree[v].s);
			return;
		}
		int m = (l+r)/2;
		flip(2*v, l, m, p);
		flip(2*v+1, m+1, r, p);
		tree[v] = tree[2*v] + tree[2*v+1];
	}
	void dfs(int v, int l, int r) {
		if(l == r) cout << tree[v].s << " ";
		else {
		int m = (l+r)/2;
		dfs(2*v, l, m);
		dfs(2*v+1, m+1, r);
		}
	}
	void print() {
		dfs(1, 0, n-1);
		cout<<endl;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m, q;
	cin >> n >> m >> q;
	vector<Counter> a(n+m, Counter(0));
	vector<int> norm(n+m, 1<<30), sz(n+m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			ll di = m+i-j-1;
			norm[di] = min(norm[di], i+j);
			norm[di+1] = min(norm[di+1], i+j);
			sz[di]++;
			sz[di+1]++;
		}
	for(int i = 0; i < n+m; i++) a[i] = Counter(sz[i]);
	vector<vector<int>> cur(n, vector<int>(m, 1));
	ll ans = 0, sm = n*m-1;
	auto flip = [&](int x, int y) -> ll {
		ll di = m+x-y-1;
		ll ret = a[di].flip(x+y-norm[di]);
		//cout << di << " " << x+y << endl;
		if(di+1 <= n+m-2)
			ret += a[di+1].flip(x+y-norm[di+1]);
		return ret;
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			ans += flip(i, j);
	}
	for(int x, y; q--;) {
		cin >> x >> y;x--,y--;
		cur[x][y]^=1;
		if(m+x-y-1!=n+m-2)
			sm += 2*cur[x][y]-1;
		cout << (ans += flip(x, y)) - sm << endl;
	}
}