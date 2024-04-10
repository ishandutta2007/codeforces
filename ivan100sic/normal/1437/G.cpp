// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = char>
struct suffix_automaton {
	struct node {
		unordered_map<T, int> next;
		int link, len;
		bool cl;
	};

	vector<node> b;
	vector<int> _topo;

	template<class U>
	suffix_automaton(const U& s) {
		b.push_back({{}, -1, 0, false});
		int last = 0;
		for (T x : s)
			last = extend(x, last);
	}

	node& operator[](int x) {
		return b[x];
	}

	int extend(T x, int last) {
		int curr = b.size();
		b.emplace_back();
		b[curr].len = b[last].len + 1;
		int p = last;
		for (; p != -1 && !b[p].next.count(x); p = b[p].link)
			b[p].next[x] = curr;
		if (p == -1) {
			b[curr].link = 0;
		} else {
			int q = b[p].next[x];
			if (b[p].len + 1 == b[q].len) {
				b[curr].link = q;
			} else {
				int clone = b.size();
				b.emplace_back(b[q]);
				b[clone].len = b[p].len + 1;
				b[clone].cl = true;
				for (; p != -1 && b[p].next[x] == q; p = b[p].link)
					b[p].next[x] = clone;
				b[curr].link = b[q].link = clone;
			}
		}
		return curr;
	}

	int operator()(int x, T y) {
		if (x == -1) return -1;
		auto it = b[x].next.find(y);
		return it == b[x].next.end() ? -1 : it->second;
	}

	const vector<int>& topo() {
		auto& v = _topo;
		if (!v.size()) {
			v.resize(b.size());
			iota(begin(v), end(v), 0);
			sort(begin(v), end(v), [&](int i, int j) { return b[i].len < b[j].len; });
		}
		return v;
	}

	template<class F, class G>
	auto dp_tree(F f, G g) {
		auto& t = topo();
		int n = b.size();
		vector<decltype(f(0))> v(n);
		for (int i=0; i<n; i++)
			v[i] = f(i);
		for (int i=n-1; i; i--) {
			int y = t[i], x = b[y].link;
			v[x] = g(v[x], v[y]);
		}
		return v;
	}

	vector<int> firstpos() {
		return dp_tree(
			[&](int i) { return b[i].cl ? numeric_limits<int>::max() : b[i].len; },
			[](int x, int y) { return min(x, y); });
	}

	vector<int> lastpos() {
		return dp_tree(
			[&](int i) { return b[i].cl ? numeric_limits<int>::max() : b[i].len; },
			[](int x, int y) { return max(x, y); });
	}

	vector<int> endpos_size() {
		return dp_tree([&](int i) { return 1 - b[i].cl; }, plus<int>());
	}
};

struct custom_segtree {
	const static int maxn = 1 << 19;
	vector<int> a;
	vector<pair<int*, int>> st;

	custom_segtree() {
		a.assign(2*maxn, -1);
	}

	void flag() {
		st.push_back({nullptr, 0});
	}

	void mark(int& x) {
		st.push_back({&x, x});
	}

	void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn) {
		if (r <= xl || xr <= l) return;
		if (l <= xl && xr <= r) {
			if (v > a[x]) {
				mark(a[x]);
				a[x] = v;
			}
			return;
		}
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm, xr);
	}

	int operator() (int x) {
		int v = -1;
		x += maxn;
		while (x) {
			v = max(v, a[x]);
			x >>= 1;
		}
		return v;
	}

	void rollback() {
		while (1) {
			auto [p, v] = st.back();
			st.pop_back();
			if (!p) return;
			*p = v;
		}
	}
} cs;

struct sus {
	int id, val, l, r;
};

struct updt {
	int l, r, val;
};

int n, m;
string s[300005], p;
int sa_node[300005];
int val[300005], upd[300005];
int qp[300005];
int inq[600005];
vector<sus> vs;
suffix_automaton<char> sa("");
vector<updt> vu[1200005];
basic_string<int> es[1200005];
vector<int> lp, epsz;
int sol[300005];

void dfs(int x) {
	cs.flag();
	for (auto [l, r, v] : vu[x]) {
		cs.update(l, r, v);
	}
	for (int y : es[x]) {
		dfs(y);
	}

	if (lp[x] < 1e9) {
		int qid = inq[lp[x]];
		sol[qid] = max(sol[qid], cs(qid));
	}

	cs.rollback();
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	for (int i=0; i<m; i++) {
		sol[i] = -1;
		qp[i] = p.size();
		int t;
		cin >> t;
		if (t == 1) {
			int id, nuval;
			cin >> id >> nuval;
			id--;
			vs.push_back({id, val[id], upd[id], i});
			val[id] = nuval;
			upd[id] = i;
		} else {
			string t;
			cin >> t;
			p += t;
			p += '#';
			for (int j=qp[i]; j<(int)p.size(); j++) {
				inq[j] = i;
			}
		}
	}
	qp[m] = p.size();

	// daj preostale
	for (int i=0; i<n; i++) {
		vs.push_back({i, val[i], upd[i], m});
	}

	sa = suffix_automaton(p);

	for (int i=0; i<n; i++) {
		int t = 0;
		for (char c : s[i]) {
			t = sa(t, c);
		}
		sa_node[i] = t;
		// cerr << "str sa node " << s[i] << " -> " << sa_node[i] << '\n';
	}

	for (auto [id, val, l, r] : vs) {
		if (sa_node[id] != -1) {
			vu[sa_node[id]].push_back({l, r, val});
		}
	}

	lp = sa.firstpos();
	epsz = sa.endpos_size();

	for (int i=1; i<(int)sa.b.size(); i++) {
		es[sa.b[i].link] += i;
	}

	dfs(0);

	for (int i=0; i<m; i++) {
		if (qp[i] < qp[i+1]) {
			cout << sol[i] << '\n';
		}
	}
}