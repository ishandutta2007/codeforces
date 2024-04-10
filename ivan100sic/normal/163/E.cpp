#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct aho_corasick {
	struct node {
		map<char, int> next;
		int link;
		int cnt;
		bool solved;
		int total;

		node() : next(), link(0), cnt(0), solved(false), total(0) {}
	};

	vector<pair<string, int>> src;
	vector<node> b;

	aho_corasick() {
		b.push_back(node());
	}

	void trie_add(const string& s, int w) {
		int y = 0;
		for (char x : s) {
			if (b[y].next.count(x)) {
				y = b[y].next[x];
			} else {
				y = b[y].next[x] = b.size();
				b.push_back(node());
			}
		}
		b[y].cnt += w;
	}

	void bfs() {
		b[0].link = -1;
		basic_string<int> q = {0};
		size_t qs = 0;
		while (q.size() != qs) {
			int x = q[qs++];
			for (auto [c, y] : b[x].next) {
				int t = b[x].link;
				while (t != -1 && b[t].next.count(c) == 0)
					t = b[t].link;
				if (t != -1) {
					b[y].link = b[t].next[c];
				} else {
					b[y].link = 0;
				}
				q += y;
			}
		}

		for (int x : q) {
			b[x].total = b[x].cnt;
			if (b[x].link != -1) {
				b[x].total += b[b[x].link].total;
			}
		}
	}

	void add_string(const string& b, int w) {
		src.emplace_back(b, w);
	}

	void construct() {
		for (const auto& [b, w] : src) {
			trie_add(b, w);
		}
		bfs();
	}

	int size() const {
		return src.size();
	}

	int jump(int x, char c) const {
		while (x >= 0 && b[x].next.count(c) == 0) {
			x = b[x].link;
		}
		if (x == -1)
			return 0;
		else
			return b[x].next.at(c);
	}

	ll count(const string& s) const {
		ll z = 0;
		int t = 0;
		for (char x : s) {
			t = jump(t, x);
			z += b[t].total;
		}
		return z;
	}
};

int q, n;
aho_corasick ac;
string s[100005];
int th[100005], acid[100005];
basic_string<int> e[1000005];
int fl[1000005], fr[1000005], ft;

void dfs(int x) {
	fl[x] = ++ft;
	for (int y : e[x]) {
		dfs(y);
	}
	fr[x] = ++ft;
}

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<ll, 2000005> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q, n;
	cin >> q >> n;

	for (int i=0; i<n; i++) {
		cin >> s[i];
		ac.add_string(s[i], 0);
		th[i] = 1;
	}

	ac.construct();

	for (int i=0; i<n; i++) {
		int t = 0;
		for (char x : s[i]) {
			t = ac.jump(t, x);
		}
		acid[i] = t;
	}

	for (int i=0; i<(int)ac.b.size(); i++) {
		int j = ac.b[i].link;
		if (j != -1) {
			e[j] += i;
		}
	}

	dfs(0);
	for (int i=0; i<n; i++) {
		drvo.add(fl[acid[i]], 1);
		drvo.add(fr[acid[i]], -1);
	}

	while (q--) {
		string p;
		cin >> p;
		if (p[0] == '?') {
			int t = 0;
			ll z = 0;
			for (char x : p) {
				t = ac.jump(t, x);
				z += drvo.sum(fl[t]);
			}
			cout << z << '\n';
		} else if (p[0] == '+') {
			int id = stoi(p.substr(1)) - 1;
			if (!th[id]) {
				th[id] = 1;
				drvo.add(fl[acid[id]], 1);
				drvo.add(fr[acid[id]], -1);
			}
		} else if (p[0] == '-') {
			int id = stoi(p.substr(1)) - 1;
			if (th[id]) {
				th[id] = 0;
				drvo.add(fl[acid[id]], -1);
				drvo.add(fr[acid[id]], 1);
			}
		}
	}
}