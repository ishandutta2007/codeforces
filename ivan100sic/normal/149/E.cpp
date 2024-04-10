#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1123123123;

struct suffix_tree {
	vector<int> s, len, start, link;
	vector<map<int, int>> to;
	int node, pos, n;

	vector<int> mindub;

	void clear() {
		len = {INF};
		start = {0};
		link = {0};
		to = {{}};
		n = node = pos = 0;
	}

	suffix_tree() {
		clear();
	}

	suffix_tree(const string& s) {
		clear();
		for (char x : s)
			extend(x);
		mindub.assign(len.size(), INF);

		dfs();
	}

	int make_node(int p, int l) {
		len.push_back(l);
		start.push_back(p);
		link.push_back(0);
		to.push_back({});
		return (int)len.size() - 1;
	}

	void go() {
		while (pos > len[to[node][s[n - pos]]]) {
			node = to[node][s[n - pos]];
			pos -= len[node];
		}
	}

	void extend(int c) {
		s.push_back(c);
		n++;
		pos++;
		int last = 0;
		while (pos > 0) {
			go();
			int e = s[n - pos];
			int& v = to[node][e];
			int t = s[start[v] + pos - 1];
			if (v == 0) {
				v = make_node(n-pos, INF);
				link[last] = node;
				last = 0;
			} else if (t == c) {
				link[last] = node;
				return;
			} else {
				int u = make_node(start[v], pos - 1);
				to[u][c] = make_node(n-1, INF);
				to[u][t] = v;
				start[v] += pos - 1;
				len[v] -= pos - 1;
				v = u;
				link[last] = u;
				last = u;
			}

			if (node == 0)
				pos--;
			else
				node = link[node];
		}
	}

	void dfs(int x = 0, int gde = 0) {
		if (x && len[x] > 123123123)
			len[x] = n - start[x];

		if (x)
			gde += len[x];

		for (auto p : to[x]) {
			dfs(p.second, gde);
			mindub[x] = min(mindub[x], mindub[p.second]);
		}

		if (to[x].size() == 0)
			mindub[x] = n - gde;
	}

	vector<int> find(const string& p) {
		vector<int> v(p.size() + 1, -1);

		int node = 0, pos = 0;
		for (int i=0; i<(int)p.size(); i++) {
			int c = p[i];
			
			if (pos == len[node] || pos == 0) {
				pos = 0;
				if (!to[node].count(c))
					return v;
				node = to[node][c];
				pos = 1;
			} else {
				if (s[start[node] + pos] != c)
					return v;
				pos++;
			}

			v[i+1] = mindub[node];
		}

		return v;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string str, rts;
	cin >> str;
	rts = str;
	reverse(rts.begin(), rts.end());

	suffix_tree	st(str + '$');
	suffix_tree ts(rts + '$');

	int q, sol = 0;
	cin >> q;
	while (q--) {
		string p;
		cin >> p;
		string r = p;
		reverse(r.begin(), r.end());

		auto u = st.find(p);
		auto v = ts.find(r);

		for (int i=1; i<(int)p.size(); i++) {
			int x = u[i];
			int y = v[(int)p.size() - i];

			if (x == -1 || y == -1)
				continue;

			if (x + y + (int)p.size() <= (int)str.size()) {
				sol++;
				break;
			}
		}
	}

	cout << sol << '\n';
}