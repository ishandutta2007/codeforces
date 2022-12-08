#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

struct Tree {
	vector<int> ar;
	vector<int> tree;
	Tree() {}
	Tree(vector<int> _ar) : ar(_ar) {
		tree.resize(4 * ar.size());
		build(0, 0, ar.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			tree[v] = ar[l];
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}
	int get_min(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return INFi;
		if (vl <= l && r <= vr) return tree[v];
		return min(get_min(2 * v + 1, l, (l + r) / 2, vl, vr), get_min(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
	void upd(int v, int l, int r, int vv, int delt) {
		if (vv < l || vv >= r) return;
		if (r - l == 1) {
			tree[v] = delt;
			return;
		}
		upd(2 * v + 1, l, (l + r) / 2, vv, delt);
		upd(2 * v + 2, (l + r) / 2,r, vv, delt);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}
};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		vector<set<int>> bs(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			bs[a[i]].insert(i);
		}
		for (int& i : b) cin >> i;
		Tree tree = Tree(a);
		int cur_b = 0;
		int cur_a = 0;
		bool fl = true;
		while (cur_a < n && cur_b < n) {
			while (cur_a < n && a[cur_a] == INFi) cur_a++;
			//cout << cur_a << " " << cur_b << endl;
			//cout << a[cur_a] << " " << b[cur_b] << endl;
			if (cur_a == n) {
				cout << "NO\n";
				fl = false;
				break;
			}
			if (bs[b[cur_b]].empty() || *bs[b[cur_b]].rbegin() < cur_a) {
				cout << "NO\n";
				fl = false;
				break;
			}
			//cout << "kek\n";
			set<int>::iterator h = bs[b[cur_b]].lower_bound(cur_a);
			int f = *h;
			if (tree.get_min(0, 0, n, cur_a, f + 1) < b[cur_b]) {
				cout << "NO\n";
				fl = false;
				break;
			}
			else {
				a[f] = INFi;
				bs[b[cur_b]].erase(h);
				tree.upd(0, 0, n, f, INFi);
				cur_b++;
			}
		}
		if (!fl) continue;
		cout << "YES\n";
	}
	//system("pause");
	return 0;
}