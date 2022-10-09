#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// sad je pitanje da li ja ovo stvarno umem da iskucam

// https://ideone.com/sT8Vd1
// https://codeforces.com/profile/adamant

struct suffix_tree { 
	static const int INF = 1123123123;
	static const int MAXN = 400005; // 2 * duzina stringa

	int s[MAXN];
	map<int, int> to[MAXN];
	int len[MAXN], f_pos[MAXN], link[MAXN];
	int node, pos;
	int sz = 1, n = 0;

	suffix_tree() {
		clear();
	}

	void clear() {
		for (int i=0; i<sz; i++) {
			len[i] = f_pos[i] = link[i] = s[i] = 0;
			to[i].clear();
		}
		len[0] = INF;
		sz = 1;
		node = pos = n = 0;
	}

	int make_node(int p, int l) {
		f_pos[sz] = p;
		len[sz] = l;
		return sz++;
	}
	 
	void go_edge() {
		while (pos > len[to[node][s[n - pos]]]) {
			node = to[node][s[n - pos]];
			pos -= len[node];
		}
	}
	 
	void add_letter(int c) {
		s[n++] = c;
		pos++;
		int last = 0;
		while (pos > 0) {
			go_edge();
			int edge = s[n - pos];
			int& v = to[node][edge];
			int t = s[f_pos[v] + pos - 1];
			if (v == 0) {
				v = make_node(n - pos, INF);
				link[last] = node;
				last = 0;
			} else if (t == c) {
				link[last] = node;
				return;
			} else {
				int u = make_node(f_pos[v], pos - 1);
				to[u][c] = make_node(n - 1, INF);
				to[u][t] = v;
				f_pos[v] += pos - 1;
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

	int cnt[MAXN];
	ll pref_sz[MAXN];

	void dfs(int x) {
		if (x && len[x] > 123123123) {
			len[x] = n - f_pos[x];
		}

		for (auto p : to[x]) {
			dfs(p.second);
			cnt[x] += cnt[p.second];
			pref_sz[x] += pref_sz[p.second];
		}

		if (to[x].size()) {
			// unutrasnji cvor
			pref_sz[x] += (ll)cnt[x] * (x ? len[x] : 0);
		} else {
			// list
			cnt[x] = 1;
			pref_sz[x] = len[x] - 1;
		}
		
		/*
		cerr << x << ' ' << f_pos[x] << ' ' << len[x]
			 << ' ' << cnt[x] << ' ' << pref_sz[x] << '\n';
		*/
	}

	pair<int, int> solve(int x, ll k) {
		for (auto p : to[x]) {
			int y = p.second;
			if (pref_sz[y] < k) {
				k -= pref_sz[y];
				continue;
			}
			if (k <= cnt[y] * 1ll * len[y]) {
				return {y, 1 + (k-1) / cnt[y]};
			}
			return solve(y, k - cnt[y] * 1ll * len[y]);
		}
		return {-1, -1};
	}

	void dfs_find(int x, int t, vector<int>& tmp, vector<int>& v) {
		tmp.push_back(x);
		if (x == t) {
			v = tmp;
			return;
		}
		for (auto p : to[x]) {
			int y = p.second;
			dfs_find(y, t, tmp, v);
		}
		tmp.pop_back();
	}

	vector<int> find(int x) {
		vector<int> tmp, v;
		dfs_find(0, x, tmp, v);
		return v;
	}

	string solve(ll k) {
		auto p = solve(0, k);

		// cerr << "solving " << k << ' ' << p.first << ' ' << p.second << '\n';

		auto v = find(p.first);
		v.pop_back();

		string sol;

		for (int i=1; i<(int)v.size(); i++) {
			int x = v[i];
			for (int j=f_pos[x]; j<f_pos[x]+len[x]; j++)
				sol += (char)s[j];
		}

		int x = p.first;
		for (int j=f_pos[x]; j<f_pos[x]+p.second; j++)
			sol += (char)s[j];
		
		return sol;
	}
};

suffix_tree st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	string s;

	cin >> s >> k;
	n = s.size();
	if (k > n*(n+1ll) / 2) {
		cout << "No such line.\n";
		return 0;
	}

	for (char x : s)
		st.add_letter(x);
	st.add_letter('.');

	st.dfs(0);

	cout << st.solve(k) << '\n';
}