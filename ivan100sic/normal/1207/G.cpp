#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct aho {
	struct node {
		map<char, int> next, go;
		int link, el, er;
		vector<int> inv;
		node() : link(-1) {}
	};

	vector<node> b;
	vector<int> pos, q;

	aho() {}

	aho(const vector<string>& vs) {
		int m = vs.size();
		pos.resize(m);
		b.emplace_back();
		for (int i=0; i<m; i++)
			pos[i] = add(vs[i]);
		find_links();
		int t = 0;
		dfs(0, t);
	}

	int newnode() {
		b.emplace_back();
		return b.size() - 1;
	}

	int add(const string& s) {
		int x = 0;
		for (char c : s) {
			if (b[x].next.count(c))
				x = b[x].next[c];
			else
				x = b[x].next[c] = newnode();
		}
		return x;
	}

	void find_links() {
		q = {0};
		size_t qs = 0;
		while (qs != q.size()) {
			int x = q[qs++];
			for (auto [c, y] : b[x].next) {
				int z = b[x].link;
				for (; z != -1 && !b[z].next.count(c); z = b[z].link);
				if (z == -1)
					b[y].link = 0;
				else
					b[y].link = b[z].next[c];
				q.push_back(y);
			}
		}
		for (int x : q) {
			b[x].go = b[x].next;
			if (x)
				b[b[x].link].inv.push_back(x);
		}
	}

	int go(int x, char c) {
		if (x == -1)
			return 0;
		if (!b[x].go.count(c))
			b[x].go[c] = go(b[x].link, c);
		return b[x].go[c];
	}

	void dfs(int x, int& t) {
		b[x].el = t++;
		for (int y : b[x].inv)
			dfs(y, t);
		b[x].er = t;
	}
};

struct fenwick {
	vector<int> a;

	fenwick(int n) : a(n+2, 0) {}

	int get(int x) {
		int z = 0;
		for (x++; x; x-=x&-x)
			z += a[x];
		return z;
	}

	void add(int x, int y) {
		for (x++; x<(int)a.size(); x+=x&-x)
			a[x] += y;
	}
};

vector<pair<char, int>> e[400005];
vector<int*> pitanja[400005];
int ans[400005], gde[400005];
int n, q;
string sq[400005];
aho corasick;
fenwick tree(400005);

void dfs(int x, int p) {
	tree.add(corasick.b[p].el, 1);
	for (int* r : pitanja[x]) {
		*r = tree.get(corasick.b[*r].er-1)
			-tree.get(corasick.b[*r].el-1);
	}
	for (auto [c, y] : e[x])
		dfs(y, corasick.go(p, c));
	tree.add(corasick.b[p].el, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int t, x = 0;
		cin >> t;
		if (t == 2)
			cin >> x;
		char c;
		cin >> c;
		e[x].emplace_back(c, i);
	}
	cin >> q;
	vector<string> vs(q);
	for (int i=0; i<q; i++)
		cin >> gde[i] >> vs[i];
	corasick = aho(vs);
	for (int i=0; i<q; i++) {
		int ahopos = corasick.pos[i];
		int treepos = gde[i];
		ans[i] = ahopos;
		pitanja[treepos].push_back(ans+i);
	}
	dfs(0, 0);
	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}