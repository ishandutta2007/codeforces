#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

struct ist_node {
	ll cnt, sum, isum;
	ist_node* left;
	ist_node* right;

	static ll getcnt(ist_node* root) {
		return root ? root->cnt : 0;
	}

	static ll getsum(ist_node* root) {
		return root ? root->sum : 0;
	}

	static ll getisum(ist_node* root) {
		return root ? root->isum : 0;
	}

	void recalc() {
		cnt = getcnt(left) + getcnt(right);
		sum = getsum(left) + getsum(right);
		isum = getisum(left) + getisum(right) + getcnt(right) * getsum(left);
	}

} ist_node_buffer[12500000];
vector<int> free_nodes;

ist_node* new_ist_node() {
	int x = free_nodes.back();
	free_nodes.pop_back();
	ist_node_buffer[x].cnt = 0;
	ist_node_buffer[x].sum = 0;
	ist_node_buffer[x].isum = 0;
	ist_node_buffer[x].left = nullptr;
	ist_node_buffer[x].right = nullptr;

	return ist_node_buffer + x;
}

void delete_ist_node(ist_node* root) {
	int x = root - ist_node_buffer;
	free_nodes.push_back(x);
}

ist_node* add(ist_node* root, int x, int xl, int xr) {
	if (x < xl || x > xr) {
		return root;
	}
	if (!root) {
		root = new_ist_node();
	}

	if (xl == xr) {
		root->cnt = 1;
		root->sum = x;
		root->isum = 0;
		return root;
	}

	int xm = (xl + xr) >> 1;
	root->left = add(root->left, x, xl, xm);
	root->right = add(root->right, x, xm + 1, xr);
	root->recalc();
	return root;
}

void populate(ist_node* root, int xl, int xr, vector<int>& v) {
	if (!root) {
		return;
	}
	if (xl == xr) {
		v.push_back(xl);
		return;
	}
	int xm = (xl + xr) >> 1;
	populate(root->left, xl, xm, v);
	populate(root->right, xm + 1, xr, v);
}

void deallocate(ist_node* root) {
	if (!root) {
		return;
	}
	deallocate(root->left);
	deallocate(root->right);
	delete_ist_node(root);
}

struct merdzabilna_stvar {
	ist_node* root;
	int l;
	
	ll lisum() {
		return l * ist_node::getsum(root) + ist_node::getisum(root);
	}

	ll sz() const {
		return root ? root->cnt : 0;
	}

	bool operator< (const merdzabilna_stvar& b) const {
		return l < b.l;
	}
};

ll global_lisum;

merdzabilna_stvar merdzuj(merdzabilna_stvar prva, merdzabilna_stvar druga) {
	global_lisum -= prva.lisum() + druga.lisum();

	merdzabilna_stvar tmp;
	tmp.l = min(prva.l, druga.l);

	if (prva.sz() > druga.sz()) {
		swap(prva, druga);
	}

	vector<int> v;
	populate(prva.root, 1, n, v);
	deallocate(prva.root);
	for (int x : v) {
		druga.root = add(druga.root, x, 1, n);
	}
	tmp.root = druga.root;

	global_lisum += tmp.lisum();
	return tmp;
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	free_nodes.resize(12500000);
	iota(free_nodes.begin(), free_nodes.end(), 0);
	
	ll ws = 0;

	multiset<merdzabilna_stvar> s;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		ws += a * 1ll * b;
		
		merdzabilna_stvar tmp = { add(nullptr, b, 1, n), a };

		global_lisum += a * 1ll * b;

		// ubaci se pa se spajaj!
		auto it = s.insert(tmp);
		
		while (1) {
			bool nesto = false;

			// spajaj sa desnim?
			if (next(it) != s.end() && it->l + it->sz() >= next(it)->l) {
				auto ms = merdzuj(*it, *next(it));
				s.erase(next(it));
				s.erase(it);
				it = s.insert(ms);
				nesto = true;
			}

			// spajaj sa levim?
			if (it != s.begin() && prev(it)->l + prev(it)->sz() >= it->l) {
				auto ms = merdzuj(*prev(it), *it);
				s.erase(prev(it));
				s.erase(it);
				it = s.insert(ms);
				nesto = true;
			}

			if (!nesto) {
				break;
			}
		}

		cout << global_lisum - ws << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}