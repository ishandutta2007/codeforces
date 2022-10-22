#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node
{
	int l;
	int r;

	int add_a;

	int val_a;
	int val_b;

	pair<int, int> max_b;
	int count_b;

	void pop(const Node& n1, const Node& n2)
	{
		max_b = max(n1.max_b, n2.max_b);
		count_b = n1.count_b + n2.count_b;
	}
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
	nodes[idx].pop(nodes[idx * 2 + 1], nodes[idx * 2 + 2]);
}

ll solve()
{
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		b[i] = a[i] + i;
	vector<Node> tree(n * 8);

	auto update_leaf = [&](Node* node) {
		int i = node->l;
		node->val_a = a[i];
		node->val_b = b[i];
		node->max_b = { b[i], i };
		node->count_b = (b[i] >= 0 ? 1 : 0);
	};

	for (int i = 0; i < n; i++)
	{
		traverse(0, 0, n - 1, i, i, tree,
			[](Node* node) {
				node->add_a = 0;
			},
			update_leaf);
	}
	ll ret = sum;
	for (; c > 0; c--)
	{
		pair<int, int> max_b = tree[0].max_b;
		int k = max_b.second;
		sum -= a[k];
		traverse(0, 0, n - 1, k, k, tree,
			[&](Node* node) { sum -= node->add_a; },
			[](Node* node) {});

		b[k] = -1e9;
		traverse(0, 0, n - 1, k, k, tree,
			[](Node* node) {},
			update_leaf);

		traverse(0, 0, n - 1, k, n - 1, tree,
			[](Node* node) {},
			[&](Node* node) { ++node->add_a; sum += node->count_b; });

		ret = min(ret, sum);
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; case_id++)
	{
		cout << solve() << endl;
	}
	return 0;
}