#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, a, l, r;
vector<int> nums;
vector<vi> tree;

void build(int v = 1, int s = 1, int e = n) {
	if (s == e) {
		tree[v] = {nums[s - 1]};
		return;
	}
	int mid = (s + e) / 2;
	build(2 * v, s, mid);
	build(2 * v + 1, mid + 1, e);
	vector<int> tmp(tree[2 * v].begin(), tree[2 * v].end());
	tmp.insert(tmp.end(), tree[2 * v + 1].begin(), tree[2 * v + 1].end());
	for(auto& i : tmp) {
		for(auto& j : tree[v])
			i = min(i, i ^ j);
		if(i) {
			tree[v].pb(i);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	tree.resize(4 * n + 5);
	nums.resize(n);
	for (auto& i : nums)
		cin >> i, a ^= i;
	build();
	cout << (a == 0 ? -1 : (int)tree[1].size());
}