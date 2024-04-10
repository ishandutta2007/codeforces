#include <bits/stdc++.h>
using namespace std;
constexpr int N = 102000, T = 300, C = 340;
struct Node {
	int link, next[26];
	vector<int> ch, ends, q;
} t[N];
int cnt_nodes = 1;
int big[C], small[N];
void add(int pos, int val) {
	int bl = pos / T;
	for (int i = bl + 1; i < C; ++i)
		big[i] += val;
	for (int i = pos + 1; i < (bl + 1) * T; ++i)
		small[i] += val;
}
int sum(int r) {return big[r / T] + small[r];}
int sum(int l, int r) {return sum(r) - sum(l);}
void build() {
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int p = que.front();
		que.pop();
		for (int i = 0; i < 26; ++i) {
			if (t[p].next[i] == 0) {
				t[p].next[i] = t[t[p].link].next[i];
			} else {
				t[t[p].next[i]].link = t[t[p].link].next[i];
				que.push(t[p].next[i]);
			}
		}
	}
	for (int i = 2; i <= cnt_nodes; ++i)
		t[t[i].link].ch.push_back(i);
}
int main() {
	for (int i = 0; i < 26; ++i)
		t[0].next[i] = 1;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int p = 1;
		for (char c : s[i]) {
			if (t[p].next[c - 'a'] == 0)
				t[p].next[c - 'a'] = ++cnt_nodes;
			p = t[p].next[c - 'a'];
			t[p].q.push_back(i);
		}
		t[p].ends.push_back(i);
	}
	build();
	vector<vector<tuple<int, int, int>>> queries(n);
	vector<long long> ans(q);
	for (int i = 0; i < q; ++i) {
		int l, r, k;
		cin >> l >> r >> k;
		--l;
		--k;
		queries[k].emplace_back(l, r, i);
	}
	for (int i = 0; i < n; ++i) {
		if (s[i].length() > T) {
			vector<long long> sum(n + 1);
			function<int(int)> dfs = [&](int p) {
				int cnt = 0;
				for (int j : t[p].q)
					if (i == j)
						++cnt;
				for (int v : t[p].ch)
					cnt += dfs(v);
				for (int j: t[p].ends)
					sum[j + 1] = cnt;
				return cnt;
			};
			dfs(1);
			for (int i = 1; i <= n; ++i)
				sum[i] += sum[i - 1];
			for (auto q : queries[i]) {
				int l, r, j;
				tie(l, r, j) = q;
				ans[j] = sum[r] - sum[l];
			}
		}
	}
	function<void(int)> dfs = [&](int p) {
		for (int i : t[p].ends)
			add(i, 1);
		for (int i : t[p].q) {
			if (s[i].length() <= T) {
				for (auto q : queries[i]) {
					int l, r, j;
					tie(l, r, j) = q;
					ans[j] += sum(l, r);
				}
			}
		}
		for (int v : t[p].ch)
			dfs(v);
		for (int i : t[p].ends)
			add(i, -1);
	};
	dfs(1);
	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
	return 0;
}