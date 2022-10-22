#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int l;
	int r;

	int val;
};

template<class Func1, class Func2>
void traverse(int idx, int l, int r, int s, int t, vector<Node>& nodes, Func1 func1, Func2 func2)
{
	Node& n = nodes[idx];
	n.l = l;
	n.r = r;
	func1(&n);
	if (l >= s && r <= t) {
		func2(&n);
		return;
	}
	int m = (l + r) / 2;
	if (m >= s)
		traverse(idx * 2 + 1, l, m, s, t, nodes, func1, func2);
	if (m < t)
		traverse(idx * 2 + 2, m + 1, r, s, t, nodes, func1, func2);
}

int solve()
{
	int n;
	int m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> l(m);
	vector<int> r(m);
	for (int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i];
		--l[i];
		--r[i];
	}
	vector<int> mr(n, -1);
	for (int i = 0; i < m; i++)
		mr[l[i]] = max(mr[l[i]], r[i]);
	for (int i = 1; i < n; i++)
		mr[i] = max(mr[i], mr[i - 1]);
	unordered_map<int, list<int>> g;

	vector<Node> tree(n * 8);
	for (Node& n : tree)
		n.val = -1;

	auto update = [&](int s, int t, int val)
	{
		if (s > t) return;
		traverse(0, 0, n - 1, s, t, tree,
			[](Node* node) {},
			[&](Node* node) {
				node->val = max(node->val, val);
			});
	};
	auto add = [&](int s1, int t1, int s2, int t2)
	{
		update(0, s1, t1);
		update(s1 + 1, s2, t2);
		update(s2 + 1, n - 1, 1e9);
	};
	for (int i = n - 1; i >= 0; i--)
	{
		auto& w = g[a[i]];
		w.push_front(i);
		if (mr[i] >= i)
		{
			while (w.back() > mr[i])
				w.pop_back();
			int v1 = i;
			int v2 = w.back();
			if (v1 == v2)
				continue;
			int v3 = *(++w.begin());
			int v4 = *(++w.rbegin());
			add(v1, v4, v3, v2);
		}
	}

	int ret2 = n;
	for (int i = 0; i < n; i++)
	{
		int val = -1;
		traverse(0, 0, n - 1, i, i, tree,
			[&](Node* node) {
				val = max(val, node->val);
			},
			[](Node* node) {});
		ret2 = min(ret2, val - i + 1);
	}
	ret2 = max(ret2, 0);
	return ret2;
}

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; case_id++)
	{
		int ret = solve();
		printf("%d\n", ret);
	}
	return 0;
}