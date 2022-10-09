// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = char>
struct suffix_automaton {
	struct node {
		map<T, int> next;
		int link, len;
		bool is_clone;
	};

	vector<node> b;
	int last;
	vector<int> topo_cached;
	vector<int> firstpos_cached;

	void init() {
		b.push_back({{}, -1, 0, false});
		last = 0;
	}

	template<class U>
	suffix_automaton(const U& s) {
		init();
		for (T x : s)
			extend(x);
	}

	node& operator[](int x) {
		return b[x];
	}

	void extend(T x) {
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
				b[clone].is_clone = true;
				for (; p != -1 && b[p].next[x] == q; p = b[p].link)
					b[p].next[x] = clone;
				b[curr].link = b[q].link = clone;
			}
		}
		last = curr;
	}

	const vector<int>& topo() {
		auto& v = topo_cached;
		if (!v.size()) {
			v.resize(b.size());
			iota(begin(v), end(v), 0);
			sort(begin(v), end(v), [&](int i, int j) { return b[i].len < b[j].len; });
		}
		return v;
	}

	const vector<int>& firstpos() {
		auto& v = firstpos_cached;
		if (!v.size()) {
			auto& t = topo();
			v.resize(b.size(), numeric_limits<int>::max());
			for (int i=(int)b.size()-1; i; i--) {
				int j = t[i];
				if (!b[j].is_clone)
					v[j] = min(v[j], b[j].len);
				v[b[j].link] = min(v[b[j].link], v[j]);
			}
		}
		return v;
	}


	int step(int x, T y) {
		if (x == -1) return -1;
		auto it = b[x].next.find(y);
		return it == b[x].next.end() ? -1 : it->second;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s, t;
	cin >> s >> t;

	suffix_automaton sf(s);
	reverse(begin(s), end(s));
	suffix_automaton sb(s);
	reverse(begin(s), end(s));

	set<char> ss(begin(s), end(s));
	for (char x : t) {
		if (!ss.count(x)) {
			cout << "-1\n";
			return 0;
		}
	}

	vector<pair<int, int>> sol;

	int m = t.size(), l = 0, r = 0, n = s.size();
	int u = 0, v = 0;

	auto doit = [&]() {
		if (u >= 0) {
			int p = sf.firstpos()[u];
			sol.emplace_back(p - (r-l) + 1, p);
		} else {
			int p = n - sb.firstpos()[v];
			sol.emplace_back(p + (r-l), p + 1);
		}
	};

	while (r < m) {
		char x = t[r];
		int u2 = sf.step(u, x);
		int v2 = sb.step(v, x);

		if (u2 >= 0 || v2 >= 0) {
			u = u2;
			v = v2;
			r++;
			continue;
		} else {
			doit();
			l = r;
			u = v = 0;
		}
	}

	doit();

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}